#https://leetcode.com/problems/kth-largest-element-in-an-array/description/?envType=study-plan-v2&envId=leetcode-75
###############
#TLE
###############

class Solution:
    def findKthLargest(self, arr: List[int], k: int) -> int:
        
        # while k!=0:
        #     maxi=-10**9+7
        #     idx=0
        #     for i in range(len(nums)):
        #         if maxi<nums[i]:
        #             maxi=nums[i]
        #             idx=i
        #     val=nums.pop(idx)
        #     k-=1
        # return val
        #####################################
        #QUICK (SORT) FIND PIVOT, and check the position


        def pivot(arr,start,end):
            pivot=arr[end]
            position=start
            for i in range(start,end):
                if arr[i]>pivot:
                    arr[i],arr[position]=arr[position],arr[i]
                    position+=1
            arr[position],arr[end]=arr[end],arr[position]
            return position

        def quickSort(arr,start,end,k):
            if start<=end:
                p=pivot(arr,start,end)
                if p==k:
                    return arr[p]
                elif p<k:
                    return quickSort(arr,p+1,end,k)
                else:
                    return quickSort(arr,start,p-1,k)
            return -1
        result=quickSort(arr,0,len(arr)-1,k-1)
        return result
        
