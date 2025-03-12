#https://www.naukri.com/code360/problem-of-the-day/easy

from os import *
from sys import *
from collections import *
from math import *

def matchSpecificPattern(words, n, pattern):
    # Write your code here
    # Return a list of words
    result=[]
    for i in words:
        check=[]
        val=[]
        match=0
        if len(i)>len(pattern):
            pass
        else:
            for j in range(len(i)):
                if i[j] not in check and pattern[j] not in val:
                    check.append(i[j])
                    val.append(pattern[j])
                    match+=1
                else:
                    for z in range(len(check)):
                        if check[z]==i[j]:
                            if val[z]==pattern[j]:
                                match+=1
                            else:
                                break
        if match==len(pattern):
            result.append(i)

    return result
