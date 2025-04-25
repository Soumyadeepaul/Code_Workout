#https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/description/?envType=study-plan-v2&envId=leetcode-75
class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        maxi=max(candies)
        result=[]
        for i in candies:
            if i+extraCandies>=maxi:
                result.append(True)
            else:
                result.append(False)
        return result
        
