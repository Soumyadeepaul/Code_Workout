#https://leetcode.com/problems/max-consecutive-ones-iii/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        window=[]
        count=0
        maxi=0
        for i in nums:
            if i==1:
                window.append(i)
            elif i==0 and count<k:
                window.append(i)
                count+=1
            else:
                while window and window[0]!=0:
                    window.pop(0)
                if window:
                    window.pop(0)
                    count-=1
                if count<k: 
                    window.append(i)
                    count+=1
            maxi=max(len(window),maxi)
        return maxi
