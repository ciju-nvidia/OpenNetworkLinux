/**************************************************************************//**
 *
 * @file
 * @brief nvidia_common Porting Macros.
 *
 * @addtogroup nvidia_common-porting
 * @{
 *
 *****************************************************************************/
#ifndef __NVIDIA_COMMON_PORTING_H__
#define __NVIDIA_COMMON_PORTING_H__


/* <auto.start.portingmacro(ALL).define> */
#if NVIDIA_COMMON_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS == 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <memory.h>
#endif

#ifndef NVIDIA_COMMON_MALLOC
    #if defined(GLOBAL_MALLOC)
        #define NVIDIA_COMMON_MALLOC GLOBAL_MALLOC
    #elif NVIDIA_COMMON_CONFIG_PORTING_STDLIB == 1
        #define NVIDIA_COMMON_MALLOC malloc
    #else
        #error The macro NVIDIA_COMMON_MALLOC is required but cannot be defined.
    #endif
#endif

#ifndef NVIDIA_COMMON_FREE
    #if defined(GLOBAL_FREE)
        #define NVIDIA_COMMON_FREE GLOBAL_FREE
    #elif NVIDIA_COMMON_CONFIG_PORTING_STDLIB == 1
        #define NVIDIA_COMMON_FREE free
    #else
        #error The macro NVIDIA_COMMON_FREE is required but cannot be defined.
    #endif
#endif

#ifndef NVIDIA_COMMON_MEMSET
    #if defined(GLOBAL_MEMSET)
        #define NVIDIA_COMMON_MEMSET GLOBAL_MEMSET
    #elif NVIDIA_COMMON_CONFIG_PORTING_STDLIB == 1
        #define NVIDIA_COMMON_MEMSET memset
    #else
        #error The macro NVIDIA_COMMON_MEMSET is required but cannot be defined.
    #endif
#endif

#ifndef NVIDIA_COMMON_MEMCPY
    #if defined(GLOBAL_MEMCPY)
        #define NVIDIA_COMMON_MEMCPY GLOBAL_MEMCPY
    #elif NVIDIA_COMMON_CONFIG_PORTING_STDLIB == 1
        #define NVIDIA_COMMON_MEMCPY memcpy
    #else
        #error The macro NVIDIA_COMMON_MEMCPY is required but cannot be defined.
    #endif
#endif

#ifndef NVIDIA_COMMON_VSNPRINTF
    #if defined(GLOBAL_VSNPRINTF)
        #define NVIDIA_COMMON_VSNPRINTF GLOBAL_VSNPRINTF
    #elif NVIDIA_COMMON_CONFIG_PORTING_STDLIB == 1
        #define NVIDIA_COMMON_VSNPRINTF vsnprintf
    #else
        #error The macro NVIDIA_COMMON_VSNPRINTF is required but cannot be defined.
    #endif
#endif

#ifndef NVIDIA_COMMON_SNPRINTF
    #if defined(GLOBAL_SNPRINTF)
        #define NVIDIA_COMMON_SNPRINTF GLOBAL_SNPRINTF
    #elif NVIDIA_COMMON_CONFIG_PORTING_STDLIB == 1
        #define NVIDIA_COMMON_SNPRINTF snprintf
    #else
        #error The macro NVIDIA_COMMON_SNPRINTF is required but cannot be defined.
    #endif
#endif

#ifndef NVIDIA_COMMON_STRLEN
    #if defined(GLOBAL_STRLEN)
        #define NVIDIA_COMMON_STRLEN GLOBAL_STRLEN
    #elif NVIDIA_COMMON_CONFIG_PORTING_STDLIB == 1
        #define NVIDIA_COMMON_STRLEN strlen
    #else
        #error The macro NVIDIA_COMMON_STRLEN is required but cannot be defined.
    #endif
#endif

/* <auto.end.portingmacro(ALL).define> */


#endif /* __NVIDIA_COMMON_PORTING_H__ */
/* @} */
