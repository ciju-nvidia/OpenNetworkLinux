from onl.platform.base import *
from onl.platform.mellanox import *

class OnlPlatform_x86_64_mlnx_mqm9700_r0(OnlPlatformMellanox,
                                               OnlPlatformPortConfig_64x400):
    PLATFORM='x86-64-mlnx-mqm9700-r0'
    MODEL="MQM9700"
    SYS_OBJECT_ID=".9700.1"

    def baseconfig(self):
        # load modules
        import os
        # necessary if there are issues with the install
        # os.system("/usr/bin/apt-get install")
        self.syseeprom_export();
        return True
