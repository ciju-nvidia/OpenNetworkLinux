/**************************************************************************//**
 *
 *
 *
 *****************************************************************************/
#include <nvidia_common/nvidia_common_config.h>

#include "nvidia_common_log.h"

static int
datatypes_init__(void)
{
#define NVIDIA_COMMON_ENUMERATION_ENTRY(_enum_name, _desc)     AIM_DATATYPE_MAP_REGISTER(_enum_name, _enum_name##_map, _desc,                               AIM_LOG_INTERNAL);
#include <nvidia_common/nvidia_common.x>
    return 0;
}

void __nvidia_common_module_init__(void)
{
    AIM_LOG_STRUCT_REGISTER();
    datatypes_init__();
}
