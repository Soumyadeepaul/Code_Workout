#

from typing import List

def missingNumber(n: int, arr: List[int]) -> int:
    # Write your code here
    hashmap={}
    odd=set()
    for i in arr:
        if i in hashmap:
            val=hashmap[i]
            val+=1
            if val&1:#ODD
                odd.add(i)
            else:
                if i in odd:
                    odd.discard(i)
            hashmap[i]=val
        else:
            hashmap[i]=1
            odd.add(i)
    odd=list(odd)
    return odd[0]
