#https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/description/?envType=daily-question&envId=2025-05-27

class Solution:
    def differenceOfSums(self, n: int, m: int) -> int:
        num1=0
        num2=0
        for i in range(1,n+1):
            if i%m==0:
                num2+=i
            else:
                num1+=i
        return num1-num2
