#https://www.naukri.com/code360/problems/longest-common-subsequence_624879


from sys import stdin

def lcs(s, t) :
	#Your code goes here
	dp=[[0 for _ in range(len(t)+1)]for _ in range(len(s)+1)]
	for i in range(1,len(s)+1):
		element=s[i-1]
		for j in range(1,len(t)+1):
			if element==t[j-1]:
				dp[i][j]=dp[i-1][j-1]+1
			else:
				dp[i][j]=max(dp[i-1][j],dp[i][j-1])
	return dp[len(s)][len(t)]
