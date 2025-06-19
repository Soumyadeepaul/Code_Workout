#https://leetcode.com/problems/reverse-integer/description/

class Solution:
    def reverse(self, x: int) -> int:
        signNeg=0
        newx=0
        if x<0:
            signNeg=1
            x=-x
        while x:
            newx=newx*10+(x%10)
            x//=10
        if newx>2**31:
            newx=0
        if signNeg==1:
            return -newx
        return newx
