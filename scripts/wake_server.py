
#!/usr/bin/env python

import sys

def wake(mac_addr):
    try:
        from wakeonlan import wol
        wol.send_magic_packet(mac_addr)
    except ImportError as errno:
        print("Wake on lan tool not present on your system: {0}".format(errno)  )
        print ('Run: $ sudo pip install wakeonlan')

if __name__ == "__main__":
    mac_addr = '00:01:2E:6D:FC:30'
    if (len(sys.argv) < 2):
        print('Going to use the default mac address -> ' + mac_addr)
        wake(mac_addr)
    else:
        mac_addr = str(sys.argv[1])
        print('Going to wake up the computer with the address ->' + mac_addr)
        wake(mac_addr)
