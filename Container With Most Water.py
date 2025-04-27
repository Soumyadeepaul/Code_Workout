#https://leetcode.com/problems/container-with-most-water/description/?envType=study-plan-v2&envId=leetcode-75
class Solution:
    def maxArea(self, height: List[int]) -> int:
        j=len(height)-1
        i=0
        weight=j-i
        maxxi=0
        while i<j:
            contain=weight*min(height[i],height[j])
            if maxxi<contain:
                maxxi=contain
            if height[i]<height[j]:
                i+=1
            else:
                j-=1
            weight-=1
        return maxxi
