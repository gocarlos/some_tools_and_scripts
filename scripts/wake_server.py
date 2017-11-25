
#!/usr/bin/env python

import os
import sys

class bcolors:
    """ https://stackoverflow.com/questions/22886353/printing-colors-in-python-terminal
    """
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'

    def disable(self):
        self.HEADER = ''
        self.OKBLUE = ''
        self.OKGREEN = ''
        self.WARNING = ''
        self.FAIL = ''
        self.ENDC = ''

def relaunch_as_root():
    if os.geteuid() != 0:
        # os.execvp() replaces the running process, rather than launching a child
        # process, so there's no need to exit afterwards. The extra "sudo" in the
        # second parameter is required because Python doesn't automatically set $0
        # in the new process.
        os.execvp("sudo", ["sudo"] + ["python"] + sys.argv)


def try_install_wakeonlan():

    if os.geteuid() != 0:
        print("\nWe need to install the python package wakeonlan.")
        print("Please enter your password or exit.")
        relaunch_as_root()
    else:
        try:
            import pip
            pip.main(['install', "wakeonlan"])
        except e:
            print("Failed to upload to ftp: "+ str(e))
            print(bcolors.FAIL + "\nYou dont have pip installed, do that first.\nExiting...\n\n" + bcolors.ENDC)


def wake(mac_addr):
    try:
        from wakeonlan import wol
        wol.send_magic_packet(mac_addr)
    except ImportError as errno:
        print(bcolors.WARNING + "\nWake on lan tool not present on your system: {0}".format(errno) + bcolors.ENDC)
        # print ('Run: $ sudo pip install wakeonlan')
        try_install_wakeonlan()
        wake(mac_addr)

if __name__ == "__main__":
    mac_addr = '00:01:2E:6D:FC:30'
    if (len(sys.argv) < 2):
        print('Going to use the default mac address -> ' + mac_addr)
        wake(mac_addr)
    else:
        mac_addr = str(sys.argv[1])
        print('Going to wake up the computer with the address ->' + mac_addr)
        wake(mac_addr)
