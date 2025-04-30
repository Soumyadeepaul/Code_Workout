#https://github.com/Soumyadeepaul/Code_Workout/blob/main/Counting%20Bits.py

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ans=0
        for i in nums:
            ans=ans^i  #XOR, it removes the duplicate when twice present
        return ans
        #[4,1,2,1,2]
        #[100,001,010,001,010]
        #[101,010,001,010]
        #[111,001,010]
        #[110,010]
        #[100]=4
        
        
