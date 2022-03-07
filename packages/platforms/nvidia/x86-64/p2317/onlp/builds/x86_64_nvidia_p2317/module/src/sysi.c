/************************************************************
 * <bsn.cl fy=2014 v=onl>
 *
 *           Copyright 2014 Big Switch Networks, Inc.
 *
 * Licensed under the Eclipse Public License, Version 1.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 *        http://www.eclipse.org/legal/epl-v10.html
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
 *
 *
 ***********************************************************/
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <onlplib/file.h>
#include <onlp/platformi/fani.h>
#include <onlp/platformi/ledi.h>
#include <onlp/platformi/psui.h>
#include <onlp/platformi/sysi.h>
#include <onlp/platformi/thermali.h>
#include "platform_lib.h"
#include "x86_64_nvidia_p2317_int.h"
#include "x86_64_nvidia_p2317_log.h"
#include <nvidia_common/nvidia_common.h>

static const char* __ONL_PLATFORM_NAME = NULL;

int mc_get_platform_info(nvidia_platform_info_t* nvidia_platform)
{
	if (!__ONL_PLATFORM_NAME) {
		aim_strlcpy(nvidia_platform->onl_platform_name, "x86-64-nvidia-p2317-all", PLATFORM_NAME_MAX_LEN);
	}
	else {
		aim_strlcpy(nvidia_platform->onl_platform_name, __ONL_PLATFORM_NAME, PLATFORM_NAME_MAX_LEN);
	}
	nvidia_platform->led_num = CHASSIS_LED_COUNT;
	nvidia_platform->fan_num = CHASSIS_FAN_COUNT;
	nvidia_platform->thermal_num = CHASSIS_THERMAL_COUNT;
	nvidia_platform->sfp_num = SFP_PORT_COUNT;
	nvidia_platform->psu_num = CHASSIS_PSU_COUNT;
	nvidia_platform->cpld_num = CPLD_COUNT;
	nvidia_platform->psu_fixed = false;
	nvidia_platform->fan_fixed = false;
	nvidia_platform->psu_type = PSU_TYPE_3;
	nvidia_platform->led_type = LED_TYPE_3;

	return ONLP_STATUS_OK;
}

int
onlp_sysi_platform_set(const char* platform)
{
	nvidia_platform_info_t* nvidia_platform;

    if(!strcmp(platform, "x86-64-nvidia-p2317-r0")) {
        __ONL_PLATFORM_NAME = "x86-64-nvidia_p2317-r0";
        nvidia_platform = get_platform_info();
        mc_get_platform_info(nvidia_platform);
        return ONLP_STATUS_OK;
    } else if(!strcmp(platform, "x86-64-nvidia-sgx-h100-r0")) {
        __ONL_PLATFORM_NAME = "x86-64-nvidia_sgx-h100-r0";
        nvidia_platform = get_platform_info();
        mc_get_platform_info(nvidia_platform);
        return ONLP_STATUS_OK;
    } else if(!strcmp(platform, "x86-64-nvidia-hgx-h100-r0")) {
        __ONL_PLATFORM_NAME = "x86-64-nvidia_hgx-h100-r0";
        nvidia_platform = get_platform_info();
        mc_get_platform_info(nvidia_platform);
        return ONLP_STATUS_OK;
    } else if(!strcmp(platform, "x86-64-nvidia-p2317-all")) {
        __ONL_PLATFORM_NAME = "x86-64-nvidia_p2317-all";
        return ONLP_STATUS_OK;
    }

    return ONLP_STATUS_E_UNSUPPORTED;
}

int
onlp_sysi_init(void)
{
    return ONLP_STATUS_OK;
}

