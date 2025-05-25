#https://leetcode.com/problems/trapping-rain-water/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def trap(self, height: List[int]) -> int:
        leftMaxPrefix=[height[0]]
        rightMaxSuffix=[height[-1]]
        for i in height[1:]:
            leftMaxPrefix.append(max(leftMaxPrefix[-1],i))
        i=len(height)-2
        while i>-1:
            rightMaxSuffix.insert(0,max(rightMaxSuffix[0],height[i]))
            i-=1
        result=0
        for i in range(len(height)):
            result+=min(leftMaxPrefix[i],rightMaxSuffix[i])-height[i]
        return result

