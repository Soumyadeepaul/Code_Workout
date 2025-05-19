#https://leetcode.com/problems/combinations/description/?envType=study-plan-v2&envId=top-interview-150
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        def combinations(n,k,result,idx,length,stack):
            if length==k:
                result.append(list(stack))
                return result
            if idx>n:
                return result
            stack.append(idx)
            result=combinations(n,k,result,idx+1,length+1,stack)
            stack.pop()
            result=combinations(n,k,result,idx+1,length,stack)
            return result
        result=[]
        idx=1
        return combinations(n,k,result,idx,0,[])
