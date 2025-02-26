#https://www.naukri.com/code360/problems/is-graph-tree_1115787

from os import *
from sys import *
from collections import *
from math import *

def isGraphTree(n: int, edgeList: list):
    # Write your code here.
    result=edgeList[0]
    for i in edgeList[1:]:
        if i[0] in result and i[1] in result:
            return 0
        result.append(i[1])
        result.append(i[0])
    return 1
