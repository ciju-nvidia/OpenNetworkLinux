from onl.platform.base import *
from onl.platform.nvidia import *

class OnlPlatform_x86_64_nvidia_p4697_r0(OnlPlatformNvidia,
                                           OnlPlatformPortConfig_72x400):
    PLATFORM='x86-64-nvidia-p4697-r0'
    MODEL="P4697"
    SYS_OBJECT_ID=".4697.1"

    def baseconfig(self):
        # load modules
        import os
        # necessary if there are issues with the install
        # os.system("/usr/bin/apt-get install")
        self.syseeprom_export();
        return True
