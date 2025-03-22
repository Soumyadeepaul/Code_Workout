#https://www.naukri.com/code360/problems/subsequences-of-string_985087

from os import *
from sys import *
from collections import *
from math import *

def subsequences(str):

    # Write your code here
    def subsetFun(string,subset,i,ans):
        if i==len(string):
            if subset!=[]:
                ans.append(''.join(subset))
            return
        
        subset.append(string[i])
        subsetFun(string,subset,i+1,ans)
        subset.pop()
        subsetFun(string,subset,i+1,ans)
        return ans
        

    ans=subsetFun(list(str),[],0,[])
    return ans
