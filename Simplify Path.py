#https://leetcode.com/problems/simplify-path/description/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def simplifyPath(self, path: str) -> str:
        
        string=''
        stack=[]
        if path[-1]!='/':
            path+='/'
        for i in path:
            if i=='/':
                if string!='.':
                    stack.append(string)
                string=''
            else:
                string+=i
        stack1=[]
        for i in stack:
            if i=='':
                pass
            else:
                if i=='..':
                    if stack1:
                        stack1.pop()
                else:
                    stack1.append(i)
        string='/'
        for i in stack1:
            string+=i+'/'
        if len(string)==1:
            return string
        return string[:-1]
