#https://leetcode.com/problems/koko-eating-bananas/description/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        if h==len(piles):
            return max(piles)

        start=1
        end=sum(piles)

        while start<end:
            mid=start+(end-start)//2
            hourCount=0
            i=0
            while i<len(piles):
                hourCount+=piles[i]//mid
                if piles[i]%mid:
                    hourCount+=1
                i+=1
            if hourCount>h:
                start=mid+1
            else:
                result=mid #possible optimize ans
                end=mid
        return result

##############################
#LOGIC - Painter partition algo Modified
#[4,6] and hour=4
#sum=10
#mid=5
#4<5,   count+=1
#6>5   , count+=1,   rem=1
#1<5   , count+=1..... 5 is possible
#mid=3
#4>3 , count+1, rem=1
#1<3  , count+1 
#6>3   , count+1 , rem=3
#3=3,  count+1,    3 is possible
        
