#https://leetcode.com/problems/count-and-say/

class Solution:
    def countAndSay(self, n: int) -> str:
        if n==1:
            return '1'
        get=self.countAndSay(n-1)
        result=''
        previous=get[0]
        count=1
        for i in get[1:]:
            if i==previous:
                count+=1
            else:
                result+=str(count)+str(previous)
                count=1
                previous=i
        result+=str(count)+str(previous)
        count=0
        return result


