#https://www.naukri.com/code360/problem-of-the-day/easy

from typing import *


def stringReformat(s: str, k: int) -> str:
    # Write your code here
    result=""
    string=""
    for i in range(len(s)-1,-1,-1):
        if s[i]=='-':
            pass
        else:
            if len(string)==k:
                result="-"+string+result
                string=""
            value=s[i]
            if ord(value)>=97 and ord(value)<=97+26:
                value=chr(ord(value)-(97-65))
            string=str(value)+string
    if string!="":
        result=string+result
    return result

