#https://leetcode.com/problems/combination-sum-iii/description/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        
        def combination(stack,i,k,n,result):
            if len(stack)==k:
                if sum(stack)==n:
                    result.append(list(stack))
                return result

            if i>9: #maximum integer is 9
                return result
            
            stack.append(i)
            result=combination(stack,i+1,k,n,result)
            stack.pop() #backtracking
            result=combination(stack,i+1,k,n,result)
            return result
            
        return combination([],1,k,n,[])
