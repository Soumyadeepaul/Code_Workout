#https://leetcode.com/contest/weekly-contest-459/problems/check-divisibility-by-digit-sum-and-product/

class Solution:
    def checkDivisibility(self, n: int) -> bool:
        summ=0
        mull=1
        n1=n
        while n:
            rem=n%10
            n=n//10
            summ+=rem
            mull*=rem
        val=summ+mull
        if n1%val==0:
            return True
        return False
        ©leetcode
