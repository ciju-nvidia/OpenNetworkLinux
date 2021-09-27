/************************************************************
 * <bsn.cl fy=2016 v=onl>
 *
 *        Copyright 2020 Delta Networks, Inc.
 *
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

/********************************************************//**
 *
 * @file
 * @brief x86_64_nvidia_sn2201 Porting Macros.
 *
 * @addtogroup x86_64_nvidia_sn2201-porting
 * @{
 *
 ***********************************************************/
#ifndef __X86_64_NVIDIA_SN2201_PORTING_H__
#define __X86_64_NVIDIA_SN2201_PORTING_H__


/* <auto.start.portingmacro(ALL).define> */
#if X86_64_NVIDIA_SN2201_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS == 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <memory.h>
#endif

#ifndef X86_64_NVIDIA_SN2201_MALLOC
    #if defined(GLOBAL_MALLOC)
        #define X86_64_NVIDIA_SN2201_MALLOC GLOBAL_MALLOC
    #elif X86_64_NVIDIA_SN2201_CONFIG_PORTING_STDLIB == 1
        #define X86_64_NVIDIA_SN2201_MALLOC malloc
    #else
        #error The macro X86_64_NVIDIA_SN2201_MALLOC is required but cannot be defined.
    #endif
#endif

#ifndef X86_64_NVIDIA_SN2201_FREE
    #if defined(GLOBAL_FREE)
        #define X86_64_NVIDIA_SN2201_FREE GLOBAL_FREE
    #elif X86_64_NVIDIA_SN2201_CONFIG_PORTING_STDLIB == 1
        #define X86_64_NVIDIA_SN2201_FREE free
    #else
        #error The macro X86_64_NVIDIA_SN2201_FREE is required but cannot be defined.
    #endif
#endif

#ifndef X86_64_NVIDIA_SN2201_MEMSET
    #if defined(GLOBAL_MEMSET)
        #define X86_64_NVIDIA_SN2201_MEMSET GLOBAL_MEMSET
    #elif X86_64_NVIDIA_SN2201_CONFIG_PORTING_STDLIB == 1
        #define X86_64_NVIDIA_SN2201_MEMSET memset
    #else
        #error The macro X86_64_NVIDIA_SN2201_MEMSET is required but cannot be defined.
    #endif
#endif

#ifndef X86_64_NVIDIA_SN2201_MEMCPY
    #if defined(GLOBAL_MEMCPY)
        #define X86_64_NVIDIA_SN2201_MEMCPY GLOBAL_MEMCPY
    #elif X86_64_NVIDIA_SN2201_CONFIG_PORTING_STDLIB == 1
        #define X86_64_NVIDIA_SN2201_MEMCPY memcpy
    #else
        #error The macro X86_64_NVIDIA_SN2201_MEMCPY is required but cannot be defined.
    #endif
#endif

#ifndef X86_64_NVIDIA_SN2201_VSNPRINTF
    #if defined(GLOBAL_VSNPRINTF)
        #define X86_64_NVIDIA_SN2201_VSNPRINTF GLOBAL_VSNPRINTF
    #elif X86_64_NVIDIA_SN2201_CONFIG_PORTING_STDLIB == 1
        #define X86_64_NVIDIA_SN2201_VSNPRINTF vsnprintf
    #else
        #error The macro X86_64_NVIDIA_SN2201_VSNPRINTF is required but cannot be defined.
    #endif
#endif

#ifndef X86_64_NVIDIA_SN2201_SNPRINTF
    #if defined(GLOBAL_SNPRINTF)
        #define X86_64_NVIDIA_SN2201_SNPRINTF GLOBAL_SNPRINTF
    #elif X86_64_NVIDIA_SN2201_CONFIG_PORTING_STDLIB == 1
        #define X86_64_NVIDIA_SN2201_SNPRINTF snprintf
    #else
        #error The macro X86_64_NVIDIA_SN2201_SNPRINTF is required but cannot be defined.
    #endif
#endif

#ifndef X86_64_NVIDIA_SN2201_STRLEN
    #if defined(GLOBAL_STRLEN)
        #define X86_64_NVIDIA_SN2201_STRLEN GLOBAL_STRLEN
    #elif X86_64_NVIDIA_SN2201_CONFIG_PORTING_STDLIB == 1
        #define X86_64_NVIDIA_SN2201_STRLEN strlen
    #else
        #error The macro X86_64_NVIDIA_SN2201_STRLEN is required but cannot be defined.
    #endif
#endif

/* <auto.end.portingmacro(ALL).define> */


#endif /* __X86_64_NVIDIA_SN2201_PORTING_H__ */
/* @} */
