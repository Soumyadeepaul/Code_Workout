#https://leetcode.com/problems/removing-stars-from-a-string/description/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def removeStars(self, s: str) -> str:
        # s=list(s)
        # i=0
        # l=len(s)
        # while i<l:
        #     if s[i]=='*':
        #         s.pop(i)
        #         s.pop(i-1)
        #         i-=1
        #         l-=2
        #     else:
        #         i+=1
        # return ''.join(s)
        ##################################
        stack=[]
        for i in s:
            if i=="*":
                stack.pop()
            else:
                stack.append(i)
        return ''.join(stack)

        
