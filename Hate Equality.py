#https://www.naukri.com/code360/problems/hate-equality_11334976

def canYouMakeDifference(n: int, s: str) -> int:
    # Write your code here.
    initial=s[0]
    same=1
    for i in range(len(s)):
        if s[i]!=initial:
            same=0
            break
    if same==1:
        return 0
    else:
        return 1
