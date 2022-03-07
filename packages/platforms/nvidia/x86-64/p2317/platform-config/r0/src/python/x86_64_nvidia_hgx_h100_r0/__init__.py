from onl.platform.base import *
from onl.platform.nvidia import *

class OnlPlatform_x86_64_nvidia_hgx_h100_r0(OnlPlatformNvidia,
                                           OnlPlatformPortConfig_72x400):
    PLATFORM='x86-64-nvidia-hgx-h100-r0'
    MODEL="HGX_H100"
    SYS_OBJECT_ID=".hgxh100.1"

    def baseconfig(self):
        # load modules
        import os
        # necessary if there are issues with the install
        # os.system("/usr/bin/apt-get install")
        self.syseeprom_export();
        return True
