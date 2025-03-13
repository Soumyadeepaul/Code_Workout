#https://www.naukri.com/code360/problems/reverse-only-letters_1235236

from collections import *
from math import *

def reverseOnlyLetters(s):
    # Write your code here.
    s=list(s)
    first=0
    last=len(s)-1
    while first<last:
        if (ord(s[first])<97 and ord(s[first])>65+26) or ord(s[first])>122 or ord(s[first])<65:
            first+=1
        if (ord(s[last])<97 and ord(s[last])>65+26) or ord(s[last])>122 or ord(s[last])<65:
            last-=1
        if ((ord(s[first])>=97 and ord(s[first])<=122) or (ord(s[first])>=65 and ord(s[first])<=65+26)) and ((ord(s[last])>=97 and ord(s[last])<=122) or (ord(s[last])>=65 and ord(s[last])<=65+26)):
            s[first],s[last]=s[last],s[first]
            first+=1
            last-=1
    s=''.join(s)
    return s
