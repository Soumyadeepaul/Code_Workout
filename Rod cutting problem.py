#https://www.naukri.com/code360/problems/rod-cutting-problem_800284

from sys import stdin
import sys

def cutRod(price, n):

    # Write your code here.
    dp=[[0 for _ in range(n+1)] for _ in range(len(price)+1)]
    for i in range(1,n+1):
        for j in range(1,len(price)+1):
            if i>j:
                dp[i][j]=dp[i-1][j]
            else:
                dp[i][j]=max(dp[i-1][j],price[i-1]+dp[i][j-i])
    return dp[n][len(price)]

# Taking input using fast I/O.
def takeInput():
    n = int(input())

    price = list(map(int, input().strip().split(" ")))

    return price, n


# Main.
t = int(input())
while t:
    price, n = takeInput()
    print(cutRod(price, n))
    t = t-1
