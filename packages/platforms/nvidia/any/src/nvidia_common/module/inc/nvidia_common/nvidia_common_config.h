/**************************************************************************//**
 *
 * @file
 * @brief nvidia_common Configuration Header
 *
 * @addtogroup nvidia_common-config
 * @{
 *
 *****************************************************************************/
#ifndef __NVIDIA_COMMON_CONFIG_H__
#define __NVIDIA_COMMON_CONFIG_H__

#ifdef GLOBAL_INCLUDE_CUSTOM_CONFIG
#include <global_custom_config.h>
#endif
#ifdef NVIDIA_COMMON_INCLUDE_CUSTOM_CONFIG
#include <nvidia_common_custom_config.h>
#endif

/* <auto.start.cdefs(NVIDIA_COMMON_CONFIG_HEADER).header> */
#include <AIM/aim.h>
/**
 * NVIDIA_COMMON_CONFIG_INCLUDE_LOGGING
 *
 * Include or exclude logging. */


#ifndef NVIDIA_COMMON_CONFIG_INCLUDE_LOGGING
#define NVIDIA_COMMON_CONFIG_INCLUDE_LOGGING 1
#endif

/**
 * NVIDIA_COMMON_CONFIG_LOG_OPTIONS_DEFAULT
 *
 * Default enabled log options. */


#ifndef NVIDIA_COMMON_CONFIG_LOG_OPTIONS_DEFAULT
#define NVIDIA_COMMON_CONFIG_LOG_OPTIONS_DEFAULT AIM_LOG_OPTIONS_DEFAULT
#endif

/**
 * NVIDIA_COMMON_CONFIG_LOG_BITS_DEFAULT
 *
 * Default enabled log bits. */


#ifndef NVIDIA_COMMON_CONFIG_LOG_BITS_DEFAULT
#define NVIDIA_COMMON_CONFIG_LOG_BITS_DEFAULT AIM_LOG_BITS_DEFAULT
#endif

/**
 * NVIDIA_COMMON_CONFIG_LOG_CUSTOM_BITS_DEFAULT
 *
 * Default enabled custom log bits. */


#ifndef NVIDIA_COMMON_CONFIG_LOG_CUSTOM_BITS_DEFAULT
#define NVIDIA_COMMON_CONFIG_LOG_CUSTOM_BITS_DEFAULT 0
#endif

/**
 * NVIDIA_COMMON_CONFIG_PORTING_STDLIB
 *
 * Default all porting macros to use the C standard libraries. */


#ifndef NVIDIA_COMMON_CONFIG_PORTING_STDLIB
#define NVIDIA_COMMON_CONFIG_PORTING_STDLIB 1
#endif

/**
 * NVIDIA_COMMON_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS
 *
 * Include standard library headers for stdlib porting macros. */


#ifndef NVIDIA_COMMON_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS
#define NVIDIA_COMMON_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS NVIDIA_COMMON_CONFIG_PORTING_STDLIB
#endif

/**
 * NVIDIA_COMMON_CONFIG_INCLUDE_UCLI
 *
 * Include generic uCli support. */


#ifndef NVIDIA_COMMON_CONFIG_INCLUDE_UCLI
#define NVIDIA_COMMON_CONFIG_INCLUDE_UCLI 0
#endif



/**
 * All compile time options can be queried or displayed
 */

/** Configuration settings structure. */
typedef struct nvidia_common_config_settings_s {
    /** name */
    const char* name;
    /** value */
    const char* value;
} nvidia_common_config_settings_t;

/** Configuration settings table. */
/** nvidia_common_config_settings table. */
extern nvidia_common_config_settings_t nvidia_common_config_settings[];

/**
 * @brief Lookup a configuration setting.
 * @param setting The name of the configuration option to lookup.
 */
const char* nvidia_common_config_lookup(const char* setting);

/**
 * @brief Show the compile-time configuration.
 * @param pvs The output stream.
 */
int nvidia_common_config_show(struct aim_pvs_s* pvs);

/* <auto.end.cdefs(NVIDIA_COMMON_CONFIG_HEADER).header> */

#include "nvidia_common_porting.h"

#endif /* __NVIDIA_COMMON_CONFIG_H__ */
/* @} */
