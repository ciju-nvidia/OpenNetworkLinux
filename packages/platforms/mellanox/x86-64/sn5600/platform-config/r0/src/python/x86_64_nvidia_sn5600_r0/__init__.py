from onl.platform.base import *
from onl.platform.nvidia import *

class OnlPlatform_x86_64_nvidia_sn5600_r0(OnlPlatformNvidia,
                                               OnlPlatformPortConfig_64x400):
    PLATFORM='x86-64-nvidia-sn5600-r0'
    MODEL="SN5600"
    SYS_OBJECT_ID=".sn5600.1"

    def baseconfig(self):
        # load modules
        import os
        # necessary if there are issues with the install
        # os.system("/usr/bin/apt-get install")
        self.syseeprom_export();
        return True
