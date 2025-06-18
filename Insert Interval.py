#https://leetcode.com/problems/insert-interval/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        if len(intervals)==0:
            return [newInterval]
        startNew=newInterval[0]
        endNew= newInterval[1]
        idx=0
        merged=False
        while idx<len(intervals):
            if merged==False:
                if startNew>=intervals[idx][0] and startNew<=intervals[idx][1]:
                    start=min(startNew,intervals[idx][0])
                    end=max(endNew,intervals[idx][1])
                    intervals[idx]=[start,end]
                    merged=True
                    
                
                elif endNew>=intervals[idx][0] and endNew<=intervals[idx][1]:
                    start=min(startNew,intervals[idx][0])
                    end=max(endNew,intervals[idx][1])
                    intervals[idx]=[start,end]
                    merged=True
                    
                
                elif startNew<=intervals[idx][0] and endNew>=intervals[idx][1]:
                    start=min(startNew,intervals[idx][0])
                    end=max(endNew,intervals[idx][1])
                    intervals[idx]=[start,end]
                    merged=True
                elif idx-1>-1 and intervals[idx-1][1]<startNew and intervals[idx][0]>endNew:
                    intervals.insert(idx,newInterval)
                    merged=True
                elif idx-1==-1 and intervals[idx][0]>endNew:
                    intervals.insert(idx,newInterval)
                    merged=True
                elif idx+1<len(intervals) and intervals[idx][1]<startNew and intervals[idx+1][0]>endNew:
                    intervals.insert(idx+1,newInterval)
                    merged=True
                elif idx+1==len(intervals) and intervals[idx][1]<startNew :
                    intervals.insert(idx+1,newInterval)
                    merged=True
            idx+=1 
        
        new=[intervals[0]]
        for start,end in intervals[1:]:
            if new[-1][1]<start:
                new.append([start,end])
            else:
                start=min(start,new[-1][0])
                end=max(end,new[-1][1])
                new.pop()
                new.append([start,end])
        return new
