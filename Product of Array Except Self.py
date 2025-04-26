#https://leetcode.com/problems/product-of-array-except-self/description/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        #IF PREFIX SUFIX array has been used, no division operation needed
        prefixMul=[1,]
        count0=0
        for i in range(1,len(nums)):
            if nums[i]==0:
                count0+=1
                if count0>1:
                    return [0]*len(nums)
            top=prefixMul[-1]
            val=nums[i-1]
            prefixMul.append(top*val)
        if count0>0 and nums[0]==0:
            return [0]*len(nums)
        if count0!=1 and nums[0]!=0:
            for i in range(len(nums)-2,-1,-1):
                if nums[i]==0:
                    top=prefixMul[i+1]
                    val=nums[i+1]
                    prefixMul[i]=top*val
                else:
                    top=prefixMul[i+1]//nums[i]
                    val=nums[i+1]
                    prefixMul[i]=top*val
        else:
            val=1     
            for i in range(len(nums)-1,-1,-1):
                if nums[i]!=0:
                    val*=nums[i]
                    prefixMul[i]=0
                else:
                    prefixMul[i]=prefixMul[i]*val
        return prefixMul
        
