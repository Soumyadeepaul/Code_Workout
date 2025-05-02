#https://leetcode.com/problems/minimum-size-subarray-sum/description/?envType=problem-list-v2&envId=9bpnltid

class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        # minn=10**9 +7
        # for i in range(len(nums)):
        #     for j in range(i,len(nums)):
        #         if sum(nums[i:j+1])>=target:
        #             minn=min(minn,j-i+1)
        # if minn==10**9 +7:
        #     return 0
        # return minn
        ################################
        #LOGIC : window , if window value>=target, start poping out from front till lower value arrives
        window=[]
        i=0
        windowSum=0
        minn=10**9+7
        l=len(nums)
        windowSize=0
        while i<l:
            windowSum+=nums[i]
            window.append(nums[i])
            windowSize+=1
            if windowSum>=target:
                minn=min(minn,windowSize)
                while window:
                    val=window.pop(0)
                    windowSum-=val
                    windowSize-=1
                    if windowSum>=target:
                        minn=min(minn,windowSize)
                    else:
                        break
            i+=1
        if minn==10**9+7:
            return 0
        return minn
        
