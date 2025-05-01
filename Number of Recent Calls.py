#https://leetcode.com/problems/number-of-recent-calls/description/?envType=study-plan-v2&envId=leetcode-75

class RecentCounter:

    def __init__(self):
        self.queue=[]
        self.ans=[None]

    def ping(self, t: int) -> int:
        rangeStart=t-3000
        count=0
        i=len(self.queue)-1
        while i>-1:
            if self.queue[i]>=rangeStart:
                count+=1
                i-=1
            else:
                break
        self.queue.append(t)
        self.ans.append(count+1)
        return self.ans[-1]


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)
