#https://www.naukri.com/code360/problems/print-all-divisors-of-a-number_1164188

from typing import List

def printDivisors(n: int) -> List[int]:
    # Write your code here
    result=[n]
    for i in range(n//2,0,-1):
        if not n%i:
            result.insert(0,i)
    return result
