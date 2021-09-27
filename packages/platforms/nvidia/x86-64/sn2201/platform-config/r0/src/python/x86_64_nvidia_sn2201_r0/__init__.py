#!/usr/bin/python

from onl.platform.base import *
from onl.platform.nvidia import *

from fcntl import ioctl
import socket
import struct

class OnlPlatform_x86_64_nvidia_sn2201_r0(OnlPlatformNvidia,
                                          OnlPlatformPortConfig_48x1_4x10):
    PLATFORM='x86-64-nvidia-sn2201-r0'
    MODEL="SN2201"
    SYS_OBJECT_ID=".48.14"

    def baseconfig(self):
        # Insert platform drivers

        # Insert the drivers of Mellanox Firmware Tools (MFT)
        self.insmod("mst_pci.ko")
        self.insmod("mst_pciconf.ko")

        ########### initialize I2C bus 1 ###########
        self.new_i2c_devices (
            [
            ]
        )

        return True
