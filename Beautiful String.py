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




##############################################################################################


def makeBeautiful(str):
	# Write your code here
	start0=''
	start1=''
	l=len(str)
	alt=0
	for i in range(l):

		if alt==0:
			start0+='0'
			start1+='1'
			alt=1
		else:
			start1+='0'
			start0+='1'
			alt=0
	start0Min=0
	start1Min=0
	for i in range(l):
		#start 0
		
		if start0[i]==str[i]:
			pass
		else:
			start0Min+=1


		#start1
		if start1[i]==str[i]:
			pass
		else:
			start1Min+=1
	return min(start0Min,start1Min)
