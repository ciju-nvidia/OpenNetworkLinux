/**************************************************************************//**
 *
 * nvidia_common Internal Header
 *
 *****************************************************************************/
#ifndef __NVIDIA_COMMON_INT_H__
#define __NVIDIA_COMMON_INT_H__

#include <nvidia_common/nvidia_common_config.h>
#include <nvidia_common/nvidia_common.h>

#define MAX_NUM_OF_CPLD				4
#define PREFIX_PATH_ON_CPLD_DEV		HW_MANAGEMENT_PATH"/system"

nvidia_platform_info_t* get_platform_info(void);

#endif /* __NVIDIA_COMMON_INT_H__ */
