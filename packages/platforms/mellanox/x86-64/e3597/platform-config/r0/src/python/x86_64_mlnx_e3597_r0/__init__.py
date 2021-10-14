from onl.platform.base import *
from onl.platform.mellanox import *

class OnlPlatform_x86_64_mlnx_e3597_r0(OnlPlatformMellanox,
                                               OnlPlatformPortConfig_64x400):
    PLATFORM='x86-64-mlnx-e3597-r0'
    MODEL="E3597"
    SYS_OBJECT_ID=".3597.1"

    def baseconfig(self):
        # load modules
        import os
        # necessary if there are issues with the install
        # os.system("/usr/bin/apt-get install")
        self.syseeprom_export();
        return True
