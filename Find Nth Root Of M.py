#

# def NthRoot(n: int, m: int) -> int:
#     # Write Your Code Here
    
#     #binary search
#     start=0
#     end=m//2
#     while start<=end:
#         mid=start+(end-start)//2
#         ans=mid**n
#         if ans==m:
#             return mid
#         elif ans>m:
#             end=mid-1
#         else:
#             start=mid+1
#     return -1

####################################################
#https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1
#User function Template for python3

class Solution:
	def nthRoot(self, n: int, m: int) -> int:
		# Code here
		#binary search
        start=0
        end=m
        binN=''
        while n:
            rem=n%2
            n=n//2
            binN=str(rem)+binN
        #print(binN)
        
        while start<=end:
            mid=start+(end-start)//2
            #ans=mid**n
            i=len(binN)-1
            ans=1
            val=mid
            while i>-1:
                if binN[i]=='1':
                    ans*=val
                val=val*val
                i-=1
            #print(ans,mid)
            if ans==m:
                return mid
            elif ans>m:
                end=mid-1
            else:
                start=mid+1
        return -1
