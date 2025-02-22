#https://www.naukri.com/code360/problems/power-of-two_893061

def isPowerOfTwo(n:int) -> bool:
    # Write your code here
    while n:
        if n==1:
            return 1
        if n%2!=0:
            return 0
        n=n//2
    return 1
