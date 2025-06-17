#https://leetcode.com/problems/summary-ranges/description/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        result=[]
        stack=[]
        for i in nums:
            if stack:
                if stack[-1]+1==i:
                    if len(stack)==2:
                        stack.pop()
                    stack.append(i)
                else:
                    if len(stack)==2:
                        result.append(str(stack[0])+'->'+str(stack[1]))
                    else:
                        result.append(str(stack[0]))
                    stack=[i]
            else:
                stack.append(i)
        if len(stack)==1:
            result.append(str(stack[0]))
        elif len(stack)==2:
            result.append(str(stack[0])+'->'+str(stack[1]))
        return result
