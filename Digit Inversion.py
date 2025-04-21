#https://www.naukri.com/code360/problems/digit-inversion_985255

from os import *
from sys import *
from collections import *
from math import *

def digitInverse(n):
    # Write your code here.
    
    if n==0:
        return 9
    ans=''
    while n:
        rem=n%10
        n=n//10
        rem=9-rem
        ans=str(rem)+ans
    not0=0
    for i in ans:
        if i!='0':
            not0=1
    if not0==1:
        return int(ans)
    return 0

# Main.
t = int(input())
for i in range(t):
    n = int(input())
    print(digitInverse(n))
