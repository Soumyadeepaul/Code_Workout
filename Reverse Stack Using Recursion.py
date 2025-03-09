#https://www.naukri.com/code360/problems/reverse-stack-using-recursion_631875

from typing import List

def reverseStack(stack: List[int]) -> None:
    # Write your code here.
    if stack:
        hold=stack.pop()
        reverseStack(stack)
        stack.insert(0,hold)
