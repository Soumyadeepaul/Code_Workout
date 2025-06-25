#

def fahrenheitToCelsius(s, e, w):
	# Write your code here.
	result=[]
	for i in range(s,e+1,w):
		c=(i-32)*(5/9)
		result.append([i,int(c)])
	return result
