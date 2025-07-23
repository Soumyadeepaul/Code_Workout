#https://leetcode.com/problems/subsets/description/

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        
        def subset(nums,i,result,stack):
            if i==len(nums):
                result.append(list(stack))
            else:
                stack.append(nums[i])
                result=subset(nums,i+1,result,stack)
                stack.pop()
                result=subset(nums,i+1,result,stack)
            return result
        return subset(nums,0,[],[])

        
