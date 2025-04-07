#https://leetcode.com/problems/wildcard-matching/description/

class Solution:
    def isMatch(self, text: str, pattern: str) -> bool:
        dp=[[False for _ in range(len(pattern)+1)]for _ in range(len(text)+1)]
        starFirst=0
        for i in range(len(text)+1):
            for j in range(len(pattern)+1):
                if i==0:
                    if j==0:
                        dp[i][j]=True
                    elif pattern[j-1]=='*' and starFirst!=1:
                        dp[i][j]=True
                    else:
                        dp[i][j]=False
                        starFirst=1
                elif j>0:
                    if text[i-1]==pattern[j-1] or pattern[j-1]=='?':
                        dp[i][j]=dp[i-1][j-1]
                    elif pattern[j-1]=='*':
                        dp[i][j]=max(dp[i-1][j], dp[i][j-1])
        return dp[len(text)][len(pattern)]
        
