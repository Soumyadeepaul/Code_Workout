#https://www.naukri.com/code360/problems/remove-consecutive-duplicates_893195

def removeDuplicate(n, s):
	
	# Write Your code here.
	i=0
	while i+1<n:
		if s[i]==s[i+1]:
			s=s[:i]+s[i+1:]
			n-=1
		else:
			i+=1
	return As
