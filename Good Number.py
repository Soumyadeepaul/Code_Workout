#https://www.naukri.com/code360/problem-of-the-day/moderate

def isGoodNumber(n: int) -> bool:
    # write your code here
    i=100
    while n!=1:
        val=0
        while n:
            re=n%10
            n=n//10
            val+=re*re
        n=val
        if i==0:
            return False
        i-=1
    return True
