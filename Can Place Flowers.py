#https://leetcode.com/problems/can-place-flowers/description/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        prev=0
        curr=0
        l=len(flowerbed)
        while n!=0 and curr<l:
            if flowerbed[curr]==1:
                pass
            else:
                if flowerbed[prev]==0 and (curr+1<l and flowerbed[curr+1]==0):
                    n-=1
                    flowerbed[curr]=1
                elif flowerbed[prev]==0 and (curr+1==l):
                    n-=1
                    flowerbed[curr]=1
            prev=curr
            curr+=1
        if n==0:
            return True
        return False
        
