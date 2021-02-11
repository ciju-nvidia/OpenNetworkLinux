from onl.platform.base import *
from onl.platform.mellanox import *

class OnlPlatform_x86_64_mlnx_x86_r0(OnlPlatformMellanox,
                                           OnlPlatformPortConfig_32x40):
    PLATFORM='x86-64-mlnx-x86-r0'
    MODEL="X86"
    SYS_OBJECT_ID=".3700.3"

    def baseconfig(self):
        # load modules
        import os
        # necessary if there are issues with the install
        # os.system("/usr/bin/apt-get install")
        self.syseeprom_export();
        return True
