#https://leetcode.com/problems/evaluate-reverse-polish-notation/?envType=study-plan-v2&envId=top-interview-150

import math
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack=[]
        for i in tokens:

            if i not in '+-/*':
                stack.append(int(i))
            else:
                y=stack.pop()
                x=stack.pop()
                if i=='+':
                    stack.append(x+y)
                elif i=='-':
                    stack.append(x-y)
                elif i=='*':
                    stack.append(x*y)
                elif i=='/':
                    val=x/y
                    if val<0:
                        stack.append(math.ceil(val))
                    else:
                        stack.append(math.floor(val))
        return stack[0]
