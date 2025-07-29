#

from os import *
from sys import *
from collections import *
from math import *

def reverseStringsInParentheses(s, n):

    # Write your code here.

    stack=[]
    for i in s:
        if i!=')':
            stack.append(i)
        else:
            vals=[]
            while stack:
                x=stack.pop()
                if x=='(':
                    break
                else:
                    vals.append(x)
            stack.extend(vals)
        
    return ''.join(stack)

