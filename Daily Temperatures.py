#https://leetcode.com/problems/daily-temperatures/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        
        #Similar to next greater element
        #Monotonic stack

        result=[0]
        stack=[[temperatures[-1],len(temperatures)-1]] #array index is needed to be stored

        for i in range(len(temperatures)-2,-1,-1):
            
            while stack and temperatures[i]>=stack[-1][0]:
                stack.pop()

            if not stack:
                count=0
            else:
                count=stack[-1][1]-i #just cal. the index difference
            stack.append([temperatures[i],i])
            result.insert(0,count)

        return result
            
