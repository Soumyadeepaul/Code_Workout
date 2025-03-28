#https://www.naukri.com/code360/problems/minimum-insertions-to-make-palindrome_985293

from sys import *
from collections import *
from math import *

def minInsertion(str):
    # Write the function here.
    

    #n-longest palindromic subsequence
    #it is so because n is the maximum insertion to make it palindrom (reverse and append)
    #find lps (no.) that is already palindromic
    # abca
    #here aa is lps
    #therefore.....a bc (cb) a 


    #lps
    s=str
    length=len(s)
    dp=[[0 for _ in range(length)] for _ in range(length)]
    i=0
    starti=0
    startj=-1
    lengthi=length
    while i<lengthi:
        j=startj+1
        while j<length:
            if i==j:
                dp[i][j]=1
            else:
                if s[i]==s[j]:
                    dp[i][j]=2+dp[i+1][j-1]
                else:
                    dp[i][j]=max(dp[i][j-1],dp[i+1][j])
            j+=1
            i+=1
        i=starti
        startj+=1
        lengthi-=1
    
    return length-dp[0][length-1]


    
                
