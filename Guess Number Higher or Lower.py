#https://leetcode.com/problems/guess-number-higher-or-lower/description/?envType=study-plan-v2&envId=leetcode-75

# The guess API is already defined for you.
# @param num, your guess
# @return -1 if num is higher than the picked number
#          1 if num is lower than the picked number
#          otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n: int) -> int:
        start=0
        end=n
        while start<=end:
            mid=start+(end-start)//2
            get=guess(mid)
            if get>0:
                start=mid+1
            elif get<0:
                end=mid-1
            else:
                return mid
