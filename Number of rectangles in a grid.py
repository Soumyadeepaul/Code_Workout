#https://www.naukri.com/code360/problems/number-of-rectangles-in-nxm-grid_983601

def countRectangles(m, n)->int:
	# Write your code here
	# Return an integer denoting the total number of unique rectangles

	#TRICK
	
	sumRows=(n*(n+1))//2
	sumColumns=(m*(m+1))//2
	return sumColumns*sumRows
