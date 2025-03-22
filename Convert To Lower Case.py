#https://www.naukri.com/code360/problem-of-the-day/easy

from collections import *
from math import *


def toLowerCase(string: str) -> str:
    # Write your code here.
    result=''
    for i in string:
        if ord(i)>=65 and ord(i)<=65+26:
            st=chr(ord(i)+32)
            result+=st
        else:
            result+=i
    return result
