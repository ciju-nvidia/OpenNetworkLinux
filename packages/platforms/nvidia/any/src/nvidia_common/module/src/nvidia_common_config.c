/**************************************************************************//**
 *
 *
 *
 *****************************************************************************/
#include <nvidia_common/nvidia_common_config.h>

/* <auto.start.cdefs(NVIDIA_COMMON_CONFIG_HEADER).source> */
#define __nvidia_common_config_STRINGIFY_NAME(_x) #_x
#define __nvidia_common_config_STRINGIFY_VALUE(_x) __nvidia_common_config_STRINGIFY_NAME(_x)
nvidia_common_config_settings_t nvidia_common_config_settings[] =
{
#ifdef NVIDIA_COMMON_CONFIG_INCLUDE_LOGGING
    { __nvidia_common_config_STRINGIFY_NAME(NVIDIA_COMMON_CONFIG_INCLUDE_LOGGING), __nvidia_common_config_STRINGIFY_VALUE(NVIDIA_COMMON_CONFIG_INCLUDE_LOGGING) },
#else
{ NVIDIA_COMMON_CONFIG_INCLUDE_LOGGING(__nvidia_common_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef NVIDIA_COMMON_CONFIG_LOG_OPTIONS_DEFAULT
    { __nvidia_common_config_STRINGIFY_NAME(NVIDIA_COMMON_CONFIG_LOG_OPTIONS_DEFAULT), __nvidia_common_config_STRINGIFY_VALUE(NVIDIA_COMMON_CONFIG_LOG_OPTIONS_DEFAULT) },
#else
{ NVIDIA_COMMON_CONFIG_LOG_OPTIONS_DEFAULT(__nvidia_common_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef NVIDIA_COMMON_CONFIG_LOG_BITS_DEFAULT
    { __nvidia_common_config_STRINGIFY_NAME(NVIDIA_COMMON_CONFIG_LOG_BITS_DEFAULT), __nvidia_common_config_STRINGIFY_VALUE(NVIDIA_COMMON_CONFIG_LOG_BITS_DEFAULT) },
#else
{ NVIDIA_COMMON_CONFIG_LOG_BITS_DEFAULT(__nvidia_common_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef NVIDIA_COMMON_CONFIG_LOG_CUSTOM_BITS_DEFAULT
    { __nvidia_common_config_STRINGIFY_NAME(NVIDIA_COMMON_CONFIG_LOG_CUSTOM_BITS_DEFAULT), __nvidia_common_config_STRINGIFY_VALUE(NVIDIA_COMMON_CONFIG_LOG_CUSTOM_BITS_DEFAULT) },
#else
{ NVIDIA_COMMON_CONFIG_LOG_CUSTOM_BITS_DEFAULT(__nvidia_common_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef NVIDIA_COMMON_CONFIG_PORTING_STDLIB
    { __nvidia_common_config_STRINGIFY_NAME(NVIDIA_COMMON_CONFIG_PORTING_STDLIB), __nvidia_common_config_STRINGIFY_VALUE(NVIDIA_COMMON_CONFIG_PORTING_STDLIB) },
#else
{ NVIDIA_COMMON_CONFIG_PORTING_STDLIB(__nvidia_common_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef NVIDIA_COMMON_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS
    { __nvidia_common_config_STRINGIFY_NAME(NVIDIA_COMMON_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS), __nvidia_common_config_STRINGIFY_VALUE(NVIDIA_COMMON_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS) },
#else
{ NVIDIA_COMMON_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS(__nvidia_common_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef NVIDIA_COMMON_CONFIG_INCLUDE_UCLI
    { __nvidia_common_config_STRINGIFY_NAME(NVIDIA_COMMON_CONFIG_INCLUDE_UCLI), __nvidia_common_config_STRINGIFY_VALUE(NVIDIA_COMMON_CONFIG_INCLUDE_UCLI) },
#else
{ NVIDIA_COMMON_CONFIG_INCLUDE_UCLI(__nvidia_common_config_STRINGIFY_NAME), "__undefined__" },
#endif
    { NULL, NULL }
};
#undef __nvidia_common_config_STRINGIFY_VALUE
#undef __nvidia_common_config_STRINGIFY_NAME

const char*
nvidia_common_config_lookup(const char* setting)
{
    int i;
    for(i = 0; nvidia_common_config_settings[i].name; i++) {
        if(!strcmp(nvidia_common_config_settings[i].name, setting)) {
            return nvidia_common_config_settings[i].value;
        }
    }
    return NULL;
}

int
nvidia_common_config_show(struct aim_pvs_s* pvs)
{
    int i;
    for(i = 0; nvidia_common_config_settings[i].name; i++) {
        aim_printf(pvs, "%s = %s\n", nvidia_common_config_settings[i].name, nvidia_common_config_settings[i].value);
    }
    return i;
}

/* <auto.end.cdefs(NVIDIA_COMMON_CONFIG_HEADER).source> */
