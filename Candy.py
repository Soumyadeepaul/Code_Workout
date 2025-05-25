#https://leetcode.com/problems/candy/description/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def candy(self, ratings: List[int]) -> int:
        
        left=[1]
        right=[1]
        prev=ratings[0]
        for i in ratings[1:]:
            if i>prev:
                left.append(left[-1]+1)
            else:
                left.append(1)
            prev=i
        prev=ratings[-1]
        ratings=ratings[::-1]
        for i in ratings[1:]:
            if i>prev:
                right.insert(0,right[0]+1)
            else:
                right.insert(0,1)
            prev=i
        result=[]
        for i in range(len(left)):
            result.append(max(left[i],right[i]))
        return sum(result)
