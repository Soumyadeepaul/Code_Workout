#https://leetcode.com/problems/asteroid-collision/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        if sorted(asteroids)==asteroids:
            return asteroids
        stack=[]
        ast=0
        for i in asteroids:
            if len(stack)==0:
                stack.append(i)
            elif i>0:
                stack.append(i)
            else: #check only when negetaive value arrives
                while stack and stack[-1]>0 and stack[-1]<-i: #pop till the abs value is smaller of stack top
                    stack.pop()
                if stack and stack[-1]==-i:#is stack top's abs is equal pop
                    stack.pop()
                elif len(stack)==0 or stack[-1]<0: #if stack top is also neg. or empty stack. append
                    stack.append(i)
        return stack


