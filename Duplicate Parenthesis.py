#

from sys import *
from collections import *
from math import *

def duplicateParanthesis(expr: str) -> bool:
    # Write your code here
    
    stack=[]
    previousCount=0
    for i in expr:
        if i!=')':
            stack.append(i)
            previousCount=0
        else:
            count=0
            join=[]
            while stack:
                val=stack.pop()
                if val!='(':
                    count+=1
                    join.insert(0,val)
                else:
                    break
            if previousCount==count:
                return 'Yes'
            else:
                previousCount=count
                stack.extend(join)
    return 0
