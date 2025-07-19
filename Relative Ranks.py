#https://leetcode.com/problems/relative-ranks/description/?envType=problem-list-v2&envId=heap-priority-queue

class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        for i in range(len(score)):
            score[i]=[score[i],i]
        score.sort(reverse=True)
        result=['' for _ in range(len(score))]
        position=1
        for i,j in score:
            if position==1:
                result[j]='Gold Medal'
            elif position==2:
                result[j]='Silver Medal'
            elif position==3:
                result[j]='Bronze Medal'
            else:
                result[j]=str(position)
            position+=1
        return result
        
