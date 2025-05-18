#https://leetcode.com/problems/jump-game/description/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        idxx=[10**7 for _ in range(len(nums))] #from which index it is coming from
        jump=idxx.copy() #How many jump to take
        jump[0]=0
        checked=0
        for i in range(0,len(nums)):
            val=nums[i]
            jumpVal=jump[i]+1
            for j in range(checked,i+1+val):
                if j>=len(nums):
                    break
                idxx[j]=min(idxx[j],i)
                jump[j]=min(jump[j],jumpVal)
            checked=i+1+val
        print(jump,idxx)
        if jump[-1]==10**7:
            return False
        return True
    #LOGIC
    #     0 1 2 3 4 5
    #    [3,2,1,1,0,4]
    #idx=[0,0,0,1,3,4]
    #jum=[0,1,1,2,2,None]
