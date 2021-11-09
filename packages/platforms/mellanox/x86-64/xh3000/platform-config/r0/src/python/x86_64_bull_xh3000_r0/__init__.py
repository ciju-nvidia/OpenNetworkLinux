from onl.platform.base import *
#from onl.platform.mellanox import *

class OnlPlatformBull(OnlPlatformBase):
    MANUFACTURER='Bull'
    PRIVATE_ENTERPRISE_NUMBER=33049

    #
    # Some platforms rely on the output of the onie-syseeprom tool
    # and the machine.conf file to implement parts of ONLP.
    #
    def syseeprom_export(self):
        print "Caching ONIE System EEPROM..."
        onie = self.onie_syseeprom_get()
        mc = self.onie_machine_get()
        # XXX roth -- deprecated
        if 'onie_version' in mc:
            onie['0x29'] = mc['onie_version']
            self.onie_syseeprom_set(onie)

class OnlPlatform_x86_64_bull_xh3000_r0(OnlPlatformBull,
                                               OnlPlatformPortConfig_32x100):
    PLATFORM='x86-64-bull-xh3000-r0'
    MODEL="XH3000"
    SYS_OBJECT_ID=".3000.1"

    def baseconfig(self):
        # load modules
        import os
        # necessary if there are issues with the install
        # os.system("/usr/bin/apt-get install")
        self.syseeprom_export();
        return True
