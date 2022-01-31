from onl.platform.base import *
from onl.platform.nvidia import *

class OnlPlatform_x86_64_nvidia_sgx_h100_r0(OnlPlatformNvidia,
                                           OnlPlatformPortConfig_72x400):
    PLATFORM='x86-64-nvidia-sgx-h100-r0'
    MODEL="SGX_H100"
    SYS_OBJECT_ID=".sgxh100.1"

    def baseconfig(self):
        # load modules
        import os
        # necessary if there are issues with the install
        # os.system("/usr/bin/apt-get install")
        self.syseeprom_export();
        return True
