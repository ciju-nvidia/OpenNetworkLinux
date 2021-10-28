/**************************************************************************//**
 *
 *
 *
 *****************************************************************************/
#include <nvidia_common/nvidia_common_config.h>

#if NVIDIA_COMMON_CONFIG_INCLUDE_UCLI == 1

#include <uCli/ucli.h>
#include <uCli/ucli_argparse.h>
#include <uCli/ucli_handler_macros.h>

static ucli_status_t
nvidia_common_ucli_ucli__config__(ucli_context_t* uc)
{
    UCLI_HANDLER_MACRO_MODULE_CONFIG(nvidia_common)
}

/* <auto.ucli.handlers.start> */
/* <auto.ucli.handlers.end> */

static ucli_module_t
nvidia_common_ucli_module__ =
    {
        "nvidia_common_ucli",
        NULL,
        nvidia_common_ucli_ucli_handlers__,
        NULL,
        NULL,
    };

ucli_node_t*
nvidia_common_ucli_node_create(void)
{
    ucli_node_t* n;
    ucli_module_init(&nvidia_common_ucli_module__);
    n = ucli_node_create("nvidia_common", NULL, &nvidia_common_ucli_module__);
    ucli_node_subnode_add(n, ucli_module_log_node_create("nvidia_common"));
    return n;
}

#else
void*
nvidia_common_ucli_node_create(void)
{
    return NULL;
}
#endif
