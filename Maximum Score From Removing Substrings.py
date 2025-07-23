#https://leetcode.com/problems/maximum-score-from-removing-substrings/description/?envType=daily-question&envId=2025-07-23

class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        def score(s,val,code,count):
            stack=[]
            for i in s:
                if i==code[1] and stack and stack[-1]==code[0]:
                    stack.pop()
                    count+=val
                else:
                    stack.append(i)
            return [stack,count]
        s=list(s)
        count=0
        if x>=y:
            s,count=score(s,x,'ab',count)
            s,count=score(s,y,'ba',count)
        else:
            s,count=score(s,y,'ba',count)
            s,count=score(s,x,'ab',count)
        return count



        #INCORRECT
        # def recursion(s,value,x,y,idx,result):
        #     if idx>=len(s):
        #         result=max(result,value)
        #         return result
        #     for i in range(idx,len(s)):
        #         if s[i]=='a' and i+1<len(s) and s[i+1]=='b':
        #             result=recursion(s,value+x,x,y,i+2,result)
        #         elif s[i]=='b' and i+1<len(s) and s[i+1]=='a':
        #             result=recursion(s,value+y,x,y,i+2,result)
        #     return result
        
        # return recursion(s,0,x,y,0,0)

        
