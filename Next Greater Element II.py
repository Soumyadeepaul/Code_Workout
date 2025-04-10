#https://leetcode.com/problems/next-greater-element-ii/

class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        ans=[]
        stack=[]
        i=len(nums)-1
        #traversal
        while i>-1:
            while stack and stack[-1]<nums[i]:
                stack.pop()
            inserted=0
            if stack:
                if stack[-1]>nums[i]:
                    inserted=1
                    ans.insert(0,stack[-1])
                    stack.append(nums[i])
                else:
                    #non circular
                    for j in range(i+1,len(nums)):
                        if nums[j]>nums[i]:
                            inserted=1
                            ans.insert(0,nums[j])
                            #stack
                            while stack:
                                if stack[-1]<=nums[i]:
                                    stack.pop()
                                else:
                                    stack.append(nums[i])
                                    break
                            if len(stack)==0:
                                stack.append(nums[i])
                            break


                    #circular
                    if inserted!=1:
                        for j in range(0,i):
                            if nums[j]>nums[i]:
                                inserted=1
                                ans.insert(0,nums[j])
                                #stack
                                while stack:
                                    if stack[-1]<=nums[i]:
                                        stack.pop()
                                    else:
                                        stack.append(nums[i])
                                        break
                                if len(stack)==0:
                                    stack.append(nums[i])
                                break
            else:
                for j in range(0,i):
                    if nums[j]>nums[i]:
                        inserted=1
                        ans.insert(0,nums[j])
                        #stack
                        while stack:
                            if stack[-1]<=nums[j]:
                                stack.pop()
                            else:
                                stack.append(nums[i])
                                break
                        if len(stack)==0:
                            stack.append(nums[i])
                        break
            if inserted==0:
                ans.insert(0,-1)
                stack.append(nums[i])
            i-=1
        return ans


        
