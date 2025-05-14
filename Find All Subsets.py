#https://www.naukri.com/code360/problems/find-all-subsets_2041970

from typing import List

def FindAllSubsets(arr: List[int]) -> List[List[int]]:
    # Write your code here.
    
    def subset(arr,idx,stack,result):
        if idx==len(arr):
            result.append(list(stack))
            return result
        stack.append(arr[idx])
        result=subset(arr,idx+1,stack,result)
        stack.pop()
        result=subset(arr,idx+1,stack,result)
        return result
    return subset(arr,0,[],[])
