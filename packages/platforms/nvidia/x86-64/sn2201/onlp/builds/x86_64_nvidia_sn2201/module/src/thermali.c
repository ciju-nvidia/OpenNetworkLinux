/************************************************************
 * <bsn.cl fy=2014 v=onl>
 *
 *       Copyright 2014, 2015 Big Switch Networks, Inc.
 *       Copyright 2017, 2020 Delta Networks, Inc.
 *
 * Licensed under the Eclipse Public License, Version 1.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 *       http://www.eclipse.org/legal/epl-v10.html
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the
 * License.
 *
 * </bsn.cl>
 ************************************************************
 *
 * Thermal Sensor Platform Implementation.
 *
 ***********************************************************/
#include <onlp/platformi/thermali.h>
#include "x86_64_nvidia_sn2201_log.h"
#include "platform_lib.h"

/****************************************
* 1. path of "Near PSU"?                *
* 2. warning critical shutdown temp?    *
* 3. path of warning critical shutdown? *
 ***************************************/

////////////////////////////////////////////////////////////////
// THERMALS PLAT CONFIG
static plat_thermal_t plat_thermals[] = {
    [PLAT_THERMAL_ID_1] = {
        .name = "Thermal Sensor %d - PSU1",
        .temp_get_path     = "/var/run/hw_managemant/thermal/psu1_temp",

        .warning_get_path  = NULL,
        .critical_get_path = NULL,
        .shutdown_get_path = NULL,

        .def_warning  = 85000,
        .def_critical = 95000,
        .def_shutdown = 100000,

        .enable_set_thresholds = false,
    },
    [PLAT_THERMAL_ID_2] = {
        .name = "Thermal Sensor %d - PSU2",
        .temp_get_path     = "/var/run/hw_managemant/thermal/psu2_temp",

        .warning_get_path  = NULL,
        .critical_get_path = NULL,
        .shutdown_get_path = NULL,

        .def_warning  = 85000,
        .def_critical = 95000,
        .def_shutdown = 100000,

        .enable_set_thresholds = false,
    },
    [PLAT_THERMAL_ID_3] = {
        .name = "Thermal Sensor %d - Near Cage",
        .temp_get_path     = "/var/run/hw_managemant/thermal/port_amb",

        .warning_get_path  = NULL,
        .critical_get_path = NULL,
        .shutdown_get_path = NULL,

        .def_warning  = 85000,
        .def_critical = 95000,
        .def_shutdown = 100000,

        .enable_set_thresholds = false,
    },
    [PLAT_THERMAL_ID_4] = {
        .name = "Thermal Sensor %d - FAN Board",
        .temp_get_path     = "/var/run/hw_managemant/thermal/fan_amb",

        .warning_get_path  = NULL,
        .critical_get_path = NULL,
        .shutdown_get_path = NULL,

        .def_warning  = 85000,
        .def_critical = 95000,
        .def_shutdown = 100000,

        .enable_set_thresholds = false,
    },
    [PLAT_THERMAL_ID_5] = {
        .name = "Thermal Sensor %d - CPU Board",
        .temp_get_path     = "/var/run/hw_managemant/thermal/cpu_pack",

        .warning_get_path  = NULL,
        .critical_get_path = NULL,
        .shutdown_get_path = NULL,

        .def_warning  = 85000,
        .def_critical = 95000,
        .def_shutdown = 100000,

        .enable_set_thresholds = false,
    },
};

static int plat_thermal_is_valid(int id)
{
    if (id > PLAT_THERMAL_ID_INVALID && id < PLAT_THERMAL_ID_MAX) {
        if (plat_thermals[id].name)
            return 1;
    }
    return 0;
}

int onlp_thermali_init(void)
{
    int i;
    plat_thermal_t *thermal;

    for (i = 0 ; i < PLAT_THERMAL_ID_MAX - 1; i ++) {
        if (!plat_thermal_is_valid (i))
            continue;
        thermal = &plat_thermals[i];

        if (thermal->enable_set_thresholds) {
            if (thermal->warning_get_path && thermal->def_warning)
                plat_os_file_write_int(thermal->def_warning,
                                       thermal->warning_get_path,
                                       NULL);
            if (thermal->critical_get_path && thermal->def_critical)
                plat_os_file_write_int(thermal->def_critical,
                                       thermal->critical_get_path,
                                       NULL);
            if (thermal->shutdown_get_path && thermal->def_shutdown)
                plat_os_file_write_int(thermal->def_shutdown,
                                       thermal->shutdown_get_path,
                                       NULL);
        }
    }
    return ONLP_STATUS_OK;
}

/*
 * Retrieve the information structure for the given thermal OID.
 *
 * If the OID is invalid, return ONLP_E_STATUS_INVALID.
 * If an unexpected error occurs, return ONLP_E_STATUS_INTERNAL.
 * Otherwise, return ONLP_STATUS_OK with the OID's information.
 *
 * Note -- it is expected that you fill out the information
 * structure even if the sensor described by the OID is not present.
 */
int
onlp_thermali_info_get(onlp_oid_t id, onlp_thermal_info_t* info)
{
    int tid;
    int present = 1;
    plat_thermal_t *thermal;
    int value;
    int error;

    if (!ONLP_OID_IS_THERMAL(id)) {
        AIM_LOG_ERROR("Not a valid oid");
        return ONLP_STATUS_E_INVALID;
    }

    tid = ONLP_OID_ID_GET(id);

    if (!plat_thermal_is_valid(tid)) {
        AIM_LOG_ERROR("Not a valid platform thermal id");
        return ONLP_STATUS_E_INVALID;
    }

    thermal = &plat_thermals[tid];

    if (thermal->present) {
        present = thermal->present(thermal) ? 1 : 0;
    }

    memset(info, 0, sizeof(*info));

    // Fix onlp_thermal_info_t
    info->hdr.id = id;
    if (thermal->name)
        snprintf(info->hdr.description,
                 sizeof(info->hdr.description),
                 thermal->name, tid);

    if (thermal->temp_get_path)
        info->caps |= ONLP_THERMAL_CAPS_GET_TEMPERATURE;
    if (thermal->warning_get_path || thermal->def_warning)
        info->caps |= ONLP_THERMAL_CAPS_GET_WARNING_THRESHOLD;
    if (thermal->critical_get_path || thermal->def_critical)
        info->caps |= ONLP_THERMAL_CAPS_GET_ERROR_THRESHOLD;
    if (thermal->shutdown_get_path || thermal->def_shutdown)
        info->caps |= ONLP_THERMAL_CAPS_GET_SHUTDOWN_THRESHOLD;

    // Get value
    error = 0;
    if (present) {
        if (info->caps & ONLP_THERMAL_CAPS_GET_TEMPERATURE) {
            if (plat_os_file_read_int(&value,
                                      thermal->temp_get_path,
                                      NULL) < 0) {
                AIM_LOG_TRACE("plat_os_file_read_int failed for "
                              "ONLP_THERMAL_CAPS_GET_TEMPERATURE, "
                              "path=%s", thermal->temp_get_path);
                error ++;
            } else
                info->mcelsius = value;
        }
        if (info->caps & ONLP_THERMAL_CAPS_GET_WARNING_THRESHOLD) {
            if (thermal->warning_get_path) {
                if (plat_os_file_read_int(&value,
                                          thermal->warning_get_path,
                                          NULL) < 0) {
                    AIM_LOG_TRACE("plat_os_file_read_int failed for "
                                  "ONLP_THERMAL_CAPS_GET_WARNING_THRESHOLD, "
                                  "path=%s", thermal->warning_get_path);
                    error ++;
                } else
                    info->thresholds.warning = value;
            } else {
                info->thresholds.warning = thermal->def_warning;
            }
        }
        if (info->caps & ONLP_THERMAL_CAPS_GET_ERROR_THRESHOLD) {
            if (thermal->critical_get_path) {
                if (plat_os_file_read_int(&value,
                                          thermal->critical_get_path,
                                          NULL) < 0) {
                    AIM_LOG_TRACE("plat_os_file_read_int failed for "
                                  "ONLP_THERMAL_CAPS_GET_ERROR_THRESHOLD,"
                                  "path=%s", thermal->critical_get_path);
                    error ++;
                } else
                    info->thresholds.error = value;
            } else {
                    info->thresholds.error = thermal->def_critical;
            }
        }
        if (info->caps & ONLP_THERMAL_CAPS_GET_SHUTDOWN_THRESHOLD) {
            if (thermal->shutdown_get_path) {
                if (plat_os_file_read_int(&value,
                                          thermal->shutdown_get_path,
                                          NULL) < 0) {
                    AIM_LOG_TRACE("plat_os_file_read_int failed for "
                                  "ONLP_THERMAL_CAPS_GET_SHUTDOWN_THRESHOLD, "
                                  "path=%s", thermal->shutdown_get_path);
                    error ++;
                } else
                    info->thresholds.shutdown = value;
            } else {
                info->thresholds.shutdown = thermal->def_shutdown;
            }
        }
        info->status |= ONLP_THERMAL_STATUS_PRESENT;
    }

    // Check threshold
    if (info->caps & ONLP_THERMAL_CAPS_GET_TEMPERATURE) {
        if (info->caps & ONLP_THERMAL_CAPS_GET_ERROR_THRESHOLD) {
            if (info->mcelsius >= info->thresholds.error) {
                info->status |= ONLP_THERMAL_STATUS_FAILED;
            }
        }
        if (info->caps & ONLP_THERMAL_CAPS_GET_SHUTDOWN_THRESHOLD) {
            if (info->mcelsius >= info->thresholds.shutdown) {
                info->status |= ONLP_THERMAL_STATUS_FAILED;
            }
        }
    }

    return error ? ONLP_STATUS_E_INTERNAL : ONLP_STATUS_OK;
}

