#https://leetcode.com/problems/counting-bits/description/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def countBits(self, n: int) -> List[int]:
        result=[]
        i=0
        while i<n+1:
            num=i
            count=0
            while num:
                if num%2:
                    count+=1
                num=num//2
            result.append(count)
            if i!=n:
                result.append(count+1)
            i+=2
        return result
        
