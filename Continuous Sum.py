#https://www.naukri.com/code360/contests/beginner-contest-82/18763985/problems/38717?leftPanelTabValue=PROBLEM&customSource=studio_nav

def isThereValidArray(n: int, s: int) -> int:
    # Write your code here.
    num=0
    a=0
    while num<s:
        a+=1
        num=int((n/2)*(2*a+(n-1)*1))
        if num==s:
            return 1
    return 0
