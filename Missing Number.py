#https://www.naukri.com/code360/problems/missing-number_6680467

from typing import *

def missingNumber(a : List[int], N : int) -> int:
    # Write your code here.
    a=sorted(a)
    find=0
    for i in a:
        find=find+1
        if i!=find:
            return find
    return find+1
