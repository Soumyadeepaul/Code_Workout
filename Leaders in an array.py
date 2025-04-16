#https://www.naukri.com/code360/problem-of-the-day/easy

from os import *
from sys import *
from collections import *
from math import *

def findLeaders(elements, n):
    # Write your code here.
    #next greater element variation -> if stack gets empty append in answer

    stack=[elements[-1]]
    ans=[elements[-1]]
    for i in range(n-2,-1,-1):
        key=elements[i]
        while stack:
            val=stack.pop()
            if val>=key:  #if in right side greater value present, keep the stack intact
                stack.append(val)
                break
            else:
                if len(stack)==0:#when stack gets empty means no greater element in right
                    ans.insert(0,key)
                    stack.append(key)
                    break
    return ans

# Taking input using fast I/O.
def takeInput():
    n = int(input())
    elements = list(map(int, input().strip().split(" ")))

    return n, elements

# Main.
t = int(input())
while t:
    n, elements = takeInput()
    answer = findLeaders(elements, n)
    for ans in answer:
        print(ans, end=" ")
    print()
    t = t-1
