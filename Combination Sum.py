#https://www.naukri.com/code360/problems/combination-sum_981296

from copy import copy
def combSum(ARR, B):
	# Write your code here
	ARR=sorted(ARR)
	def combination(arr,subarr,B,result,i):
		if sum(subarr)>B:
			return result


		if sum(subarr)==B:
			if list(subarr) not in result:
				result.append(list(subarr))
			return result


		if i>=len(arr):
			return result

		subarr.append(arr[i])
		#take the element as many time as wanted
		result=combination(arr,subarr,B,result,i)
		#take the next element
		result=combination(arr,subarr,B,result,i+1)

		#dont take the element
		subarr.pop()
		result=combination(arr,subarr,B,result,i+1)
		return result
	result=combination(ARR,[],B,[],0)

	return result



######################################################################
#https://leetcode.com/problems/combination-sum/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result=[]
        
        def com(candidates,i,stack,target,result):
            if i>=len(candidates):
                return [result,stack]
            summ=sum(stack)
            if summ==target:
                result.append(list(stack))
                return [result,stack]
            elif summ>target:
                return [result,stack]
            stack.append(candidates[i])
            result,stack=com(candidates,i,stack,target,result)
            stack.pop()
            result,stack=com(candidates,i+1,stack,target,result)
            return [result,stack]

        result,stack=com(candidates,0,[],target,result)
        return result


