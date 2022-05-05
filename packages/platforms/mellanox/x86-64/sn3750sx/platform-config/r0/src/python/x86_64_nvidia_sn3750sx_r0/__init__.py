from onl.platform.base import *
from onl.platform.nvidia import *

class OnlPlatform_x86_64_nvidia_sn3750sx_r0(OnlPlatformNvidia,
                                               OnlPlatformPortConfig_32x200):
    PLATFORM='x86-64-nvidia-sn3750sx-r0'
    MODEL="SN3750SX"
    SYS_OBJECT_ID=".sn3750sx.1"

    def baseconfig(self):
        # load modules
        import os
        # necessary if there are issues with the install
        # os.system("/usr/bin/apt-get install")
        self.syseeprom_export();
        return True
