/**************************************************************************//**
 *
 * nvidia_platform_common Internal Header
 *
 *****************************************************************************/
#ifndef __NVIDIA_PLATFORM_COMMON_INT_H__
#define __NVIDIA_PLATFORM_COMMON_INT_H__

#include <nvidia_platform_common/nvidia_platform_common_config.h>

#ifndef KERNEL_VERSION
#define KERNEL_VERSION(a,b,c) (((a) << 16) + ((b) << 8) + (c))
#endif

int mpc_get_kernel_ver(void);

#endif /* __NVIDIA_PLATFORM_COMMON_INT_H__ */
