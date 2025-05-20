#

from os import *
from sys import *
from collections import *
from math import *

def isValidIPv4(ipAddress):
    # Write your code here.
    ipAddress=ipAddress.split('.')
    #print(ipAddress)
    if len(ipAddress)==4:
        for ip in ipAddress:
            val=''
            for i in ip:
                if i not in '0123456789':
                    return False
                else:
                    val+=i
            if val=='':
                return False
            if int(val)<0 or int(val)>255:
                return False
        return True
    else:
        return False
