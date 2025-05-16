#https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        count=len(points)
        points=sorted(points)
        newInterval=points[0]
        for start,end in points[1:]:
            if start>newInterval[1]:#Non overlapping
                newInterval=[start,end] #NEW INTERVAL 
            else:
                #New interval is the common part of 2 intervals
                newInterval[0]=max(newInterval[0],start)
                newInterval[1]=min(newInterval[1],end)
                count-=1
        return count
            
