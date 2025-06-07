#https://www.naukri.com/code360/problems/three-sum_6922132

def triplet(n: int, arr: [int]) -> [[int]]:
    # Write your code here.
    result=[]
    triplet=[]
    for i in range(n-1):
        target=-arr[i]
        setList=set()
        for j in range(i+1,n):
            find=target-arr[j]
            #always getting checking in back side like...
            #   i.........j
            #finding z ^
            if find in setList:
                result=[arr[i],arr[j],find]
                result=sorted(result)
                if result not in triplet:
                    triplet.append(result)
            setList.add(arr[j])
    return triplet





#####################################################
#https://leetcode.com/problems/3sum/?envType=study-plan-v2&envId=top-interview-150


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result=set()
        nums.sort()
        for i in range(len(nums)-2):
            js=set()
            js.add(nums[i+1])
            val1=nums[i]
            for k in range(i+2,len(nums)):
                val3=nums[k]
                find=0-(val1+val3)
                if find in js:
                    triplet=(val1,find,val3)
                    result.add(triplet) #SET + TUPLE
                js.add(val3)

        return list(result)
            
