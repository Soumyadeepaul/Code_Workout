# #https://www.naukri.com/code360/problem-of-the-day/moderate

# ################################
# #TLE
# #################################
# from os import *
# from sys import *
# from collections import *
# from math import *

# def zigzagConversion(s: str, row: int) -> str:
#     # write your code here
#     # length=len(s)
#     # columns=0
#     # trigger=1
#     # while length>0:
#     #     if trigger==1:
#     #         columns+=1 
#     #         length-=row
#     #         trigger=0
#     #     elif trigger==0:
#     #         length-=row-2
#     #         columns+=row-2
#     #         trigger=1

#     # dp=[[0 for _ in range(columns)]for _ in range(row)]
#     # i=0
#     # j=0
#     # length=len(s)
#     # idx=0
#     # while True:
#     #     while i!=row:
#     #         dp[i][j]=s[idx]
#     #         idx+=1
#     #         i+=1
#     #         if idx==length:
#     #             break
#     #     i-=1
#     #     if idx==length:
#     #         break
#     #     while i!=0:
#     #         i-=1
#     #         j+=1
#     #         if i==0:
#     #             break
#     #         dp[i][j]=s[idx]
#     #         idx+=1
#     #         if idx==length:
#     #             break
#     #     if idx==length:
#     #             break
#     # ans=''
#     # for i in dp:
#     #     for j in i:
#     #         if j!=0:
#     #             ans+=j
#     # return ans

#https://leetcode.com/problems/zigzag-conversion/?envType=study-plan-v2&envId=top-interview-150
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        cols=len(s)
        dp=[['' for _ in range(cols)]for _ in range(numRows)]
        idx=0
        j=0
        while j<cols:
            i=0
            while i<numRows and idx<len(s):
                dp[i][j]=s[idx]
                idx+=1
                i+=1
            i=numRows-2
            j+=1
            while i>0 and idx<len(s):
                dp[i][j]=s[idx]
                idx+=1
                j+=1
                i-=1
            if idx>=len(s):
                break
        result=''
        for i in dp:
            result+=''.join(i)
        return result

