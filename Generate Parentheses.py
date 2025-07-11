#https://leetcode.com/problems/generate-parentheses/description/

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:


        def p(result,stack,openCount,closeCount,n):
            if closeCount==n: #ALL CLOSE bracket ends
                result.append(stack)
                return
            if openCount!=n: #Open bracket can be used
                p(result,stack+"(",openCount+1,closeCount,n)
            if openCount>closeCount: #Without open close backet cant be there
                p(result,stack+")",openCount,closeCount+1,n)         
        result=[]
        stack=''
        openCount=0
        closeCount=0
        p(result,stack,openCount,closeCount,n)
        return result
