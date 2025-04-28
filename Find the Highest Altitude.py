#https://leetcode.com/problems/find-the-highest-altitude/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        maxi=0
        summ=0
        for i in gain:
            summ+=i
            maxi=max(maxi,summ)
        return maxi
            
        
