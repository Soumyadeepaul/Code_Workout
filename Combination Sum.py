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
		


