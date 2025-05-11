#https://leetcode.com/problems/maximum-subsequence-score/description/?envType=study-plan-v2&envId=leetcode-75

from heapq import heapify, heappush, heappop
class Solution:
    def maxScore(self, nums1: List[int], nums2: List[int], k: int) -> int:
        
        # def fun(idx,nums1,nums2,stack,result):
        #     if len(stack)==k:
        #         value1=0
        #         value2=10**9+7
        #         for i in stack:
        #             value1+=nums1[i]
        #             value2=min(value2,nums2[i])
        #         #print(value1,value2,stack)
        #         result=max(result,value1*value2)
        #         return result
        #     if idx>=len(nums1):
        #         return result

        #     stack.append(idx)
        #     result=fun(idx+1,nums1,nums2,stack,result)
        #     stack.pop()
        #     result=fun(idx+1,nums1,nums2,stack,result)
        #     return result
        
        # return fun(0,nums1,nums2,[],0)
        ############################################################
        #OPTIMIZE TRIED
        # def fun(idx,nums1,nums2,stack,result,minn,inserted):
        #     if inserted==k:
        #         result=max(result,stack*minn)
        #         return result
        #     if idx>=len(nums1):
        #         return result

        #     stack+=nums1[idx]
        #     prevMin=minn
        #     minn=min(minn,nums2[idx])
        #     inserted+=1
        #     result=fun(idx+1,nums1,nums2,stack,result,minn,inserted)
        #     stack-=nums1[idx]
        #     minn=prevMin
        #     inserted-=1
        #     result=fun(idx+1,nums1,nums2,stack,result,minn,inserted)
        #     return result
        
        # return fun(0,nums1,nums2,0,0,10**9+7,0)

        ###########################################################

        #
        new=[]
        for i in range(len(nums1)):
            new.append([nums2[i],nums1[i]])
        new=sorted(new,reverse=True)
        findInNums1=[]
        heapify(findInNums1)
        result=0
        summ=0
        for i in range(len(new)):
            summ+=new[i][1]
            heappush(findInNums1,new[i][1])
            if len(findInNums1)>k:
                val=heappop(findInNums1)
                summ-=val
            if len(findInNums1)==k:
                result=max(result,new[i][0]*summ)

        return result
