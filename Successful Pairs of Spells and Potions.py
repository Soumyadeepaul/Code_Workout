#https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        result=[]
        potions=sorted(potions)
        l=len(potions)-1
        while spells:
            val=spells.pop(0)
            if val==0:
                result.append(0)
            else:
                search=success/val
                #Binary Search
                start=0
                end=l
                while start<=end:
                    mid=start+(end-start)//2
                    if potions[mid]==search:
                        end=mid-1
                    elif potions[mid]<search:
                        start=mid+1
                    else:
                        end=mid-1
                if potions[mid]>=search:
                    mid-=1
                result.append(l-mid)
        return result
##################################
#LOGIC
#[5,1]  [2,3,4]  15
#search >= 15/5 -> 3,4 -> len 2
#search >= 15/1 ->  len 0
                

        
