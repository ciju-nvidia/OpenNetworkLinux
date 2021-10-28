/**************************************************************************//**
 *
 *
 *
 *****************************************************************************/
#include <nvidia_common/nvidia_common_config.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <AIM/aim.h>

int aim_main(int argc, char* argv[])
{
    printf("nvidia_common Utest Is Empty\n");
    nvidia_common_config_show(&aim_pvs_stdout);
    return ONLP_STATUS_OK;
}
