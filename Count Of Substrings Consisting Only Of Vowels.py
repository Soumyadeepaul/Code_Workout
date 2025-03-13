#https://www.naukri.com/code360/problems/count-of-substrings-consisting-only-of-vowels_1377941

from collections import *
from math import *

def countSubstrings(s):
    # Write your code here.
    count=1
    vowel=['a','e','i','o','u']
    total=[]
    result=0
    for i in range(len(s)-1):
        if s[i] in vowel and s[i+1] in vowel:
            count+=1
        elif s[i] in vowel and s[i+1] not in vowel:
            total.append(count)
            count=1
    if count!=1 or (len(s)==1 and s[0] in vowel):
        total.append(count)
    if len(s)!=1 and (s[-2] not in vowel and s[-1] in vowel):
        total.append(1)
    for i in total:
        if i==1:
            result+=1
        else:
            result+= (i*(i+1))//2
    return result
