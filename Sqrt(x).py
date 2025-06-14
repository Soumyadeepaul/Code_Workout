#https://leetcode.com/problems/sqrtx/description/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def mySqrt(self, x: int) -> int:
        if x==1:
            return 1
        #BINARY SEARCH
        start=1
        end=x//2
        result=0
        while start<=end:
            mid=start+(end-start)//2
            if mid*mid<=x:
                result=mid
                start=mid+1
            else:
                end=mid-1
        return result
