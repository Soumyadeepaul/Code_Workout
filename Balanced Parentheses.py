#https://www.naukri.com/code360/problems/balanced-parentheses_18445724

from typing import *

def isBalanced(S : str) -> bool:
    # Write your code here.
    stack=[]
    for i in S:
        if i==')' and stack and stack[-1]!='(':
            return 0
        elif i=='}' and stack and stack[-1]!='{':
            return 0
        elif i==']' and stack and stack[-1]!='[':
            return 0
        if i==')' and stack and stack[-1]=='(':
            stack.pop()
        elif i=='}' and stack and stack[-1]=='{':
            stack.pop()
        elif i==']' and stack and stack[-1]=='[':
            stack.pop()
        else:
            stack.append(i)
    return 1
        
