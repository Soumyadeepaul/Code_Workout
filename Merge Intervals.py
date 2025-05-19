#https://leetcode.com/problems/merge-intervals/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        prev=intervals[0]
        newInterval=[]
        for start,end in intervals[1:]:
            if prev[1]<start:#NEW INTERVAL
                newInterval.append(prev)
                prev=[start,end]
            else: #UPDATE THE ending value of previous interval
                prev[1]=max(prev[1],end)
        newInterval.append(prev)
        return newInterval
