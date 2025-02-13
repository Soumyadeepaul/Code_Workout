#

from typing import List

def value(n,a,count,x):
    for i in range(0,n):
        if a[i]>x:
            while a[i]>x:
                a[i]=a[i]//2
                count+=1
    return (count,a)
def divideByTwo(n: int, a: List[int]) -> int:
    # Write your code here
    count=0
    minn=min(a)
    count,a=value(n,a,count,min(a))
    while min(a)!=minn:
        minn=min(a)
        count,a=value(n,a,count,min(a))
    return count
