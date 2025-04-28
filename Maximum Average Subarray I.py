#https://leetcode.com/problems/maximum-average-subarray-i/submissions/1619911843/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        window=[]
        maxi=-99999999999999999999999999999999999999
        summation=0
        for i in nums:
            if len(window)<k:
                window.append(i)
                summation+=i
            else:
                val=summation/k
                maxi=max(maxi,val)
                exits=window.pop(0)
                summation-=exits
                window.append(i)
                summation+=i
        val=summation/k
        maxi=max(maxi,val)
        return maxi

        
