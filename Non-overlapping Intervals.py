#https://leetcode.com/problems/non-overlapping-intervals/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals=sorted(intervals)
        count=0
        prevEnd=intervals[0][1]

        for start,end in intervals[1:]:
            if start>=prevEnd: #new internal
                prevEnd=end #update end with new interval's end
            else:
                count+=1 #overlapping interval
                prevEnd=min(prevEnd,end) #minimum of present and prevEnd
        return count

        
