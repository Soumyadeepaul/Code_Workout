#https://www.naukri.com/code360/problem-of-the-day/easy

#optimal check failed

from os import *
from sys import *
from collections import *
from math import *


def roundRobin(process, n, quantum):

    # Write your code here.
    waiting=[0 for _ in range(n)]
    repeat=1
    while repeat:
        repeat=0
        for i in range(n):
            value=process[i]
            if value:
                if value>quantum:
                    toadd=quantum
                    process[i]-=quantum
                else:
                    toadd=value
                    process[i]=0
                
                for z in range(n):
                    if i==z or process[z]==0:
                        pass
                    else:
                        waiting[z]+=toadd
                repeat=1
        
    return waiting
