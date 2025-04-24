#

def editDistance(str1,str2):
	dp=[[0 for _ in range(len(str1)+1)] for _ in range(len(str2)+1)]
	# for i in range(len(str1)+1):
	# 	dp[0][i]=i
	# for i in range(len(str2)+1):
	# 	dp[i][0]=i
	for i in range(1,len(str2)+1):
		if str1[i-1]==str2[i-1]:
			dp[i][i]=dp[i-1][i-1]
		else:
			dp[i][i]=dp[i-1][i-1]+1  #MODIFICATION ON EDIT DISTANCE DP... only diagonal value.. if not matched add 1
	# for i in dp:
	# 	print(i)
	return dp[len(str2)][len(str1)]

def makeBeautiful(str):
	# Write your code here
	
	l=len(str)
	new1=''
	new2=''
	for i in range(l):
		if i%2==0:
			new1+='0'
			new2+='1'
		else:
			new1+='1'
			new2+='0'

	return min(editDistance(str,new1),editDistance(str,new2))
