#https://leetcode.com/problems/valid-perfect-square/description/
#BINARY SEARCH
class Solution:
    def isPerfectSquare(self, n: int) -> bool:
        if n==1:
            return True
        start=0
        end=(n//2)+1
        while start<end:
            mid=start+(end-start)//2
            val=mid*mid
            if val==n:
                return True
            else:
                if val>n:
                    #left side
                    end=mid
                else:
                    start=mid+1
        return False
