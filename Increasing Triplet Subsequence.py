#https://leetcode.com/problems/increasing-triplet-subsequence/description/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def triplet(self,arr,i,stack):
        if i==len(arr): #base case
            return False
        stack.append(arr[i]) #always append
        if len(stack)==3: #if len 3, check
            if stack[0]<stack[1] and stack[1]<stack[2]:
                return True
            else:
                return False
        # loop and skip same consequtive no. and smaller numbers
        idx=i+1
        while idx<len(arr) and stack[-1]>=arr[idx]:
            idx+=1
        ##################
        result=self.triplet(arr,idx,stack)
        if result==True:
            return True
        else:
            stack.pop() #pop the element
            idx=i+1 #loop
            while idx<len(arr) and len(stack)>0 and stack[-1]>=arr[idx]:
                idx+=1
            #####################
            result=self.triplet(arr,idx,stack)
            return result
    def increasingTriplet(self, nums: List[int]) -> bool:
        s=set(nums)
        if len(s)>2:
            return self.triplet(nums,0,[])
        else:
            return False
        
