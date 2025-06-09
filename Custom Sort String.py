#

from os import *
from sys import *
from collections import *
from math import *

def specificOrder(x: str, y: str):
    # Write your code here.
    sorting=''
    hashmap={}
    found=set()
    for i in x:
        found.add(i)
        if i not in hashmap:
            hashmap[i]=1
        else:
            hashmap[i]+=1
    
    for i in y:
        if i in hashmap:
            string=i*hashmap[i]
            sorting+=string
            found.remove(i)
    for i in found:
        string=i*hashmap[i]
        sorting+=string
            

    
    #print(sorting)
    return sorting
