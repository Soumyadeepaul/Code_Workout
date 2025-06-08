#https://leetcode.com/problems/happy-number/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def isHappy(self, n: int) -> bool:
        newNum=1
        x=0
        while newNum and x<10000:
            newNum=0
            while n:
                newNum+=(n%10)**2
                n=n//10
            n=newNum
            if newNum==1:
                return True
            x+=1
        return False
