#https://leetcode.com/problems/coin-change/description/?envType=study-plan-v2&envId=top-interview-150
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # def recursion(amountLeft,result,optimal,idx,coins):
        #     if amountLeft==0:
        #         if len(result)<optimal:
        #             optimal=len(result)
        #         return optimal
        #     elif amountLeft<0:
        #         return optimal
        #     if idx>=len(coins):
        #         return optimal
        #     result.append(coins[idx])
        #     amountLeft-=coins[idx]
        #     optimal=recursion(amountLeft,result,optimal,idx,coins)
        #     result.pop()
        #     amountLeft+=coins[idx]
        #     optimal=recursion(amountLeft,result,optimal,idx+1,coins)
        #     return optimal
        # optimal=recursion(amount,[],10**9+7,0,coins)
        # if optimal==10**9+7:
        #     optimal=-1
        # return optimal

        ####################################
        #DP

        dp=[0 for i in range(amount+1)]
        for i in range(1,amount+1):
            minn=10**9+7
            for j in range(len(coins)):
                if coins[j]==i:
                    dp[i]=1
                    break
                elif coins[j]<i:
                    minn=min(dp[i-coins[j]]+1,minn)
            if dp[i]!=1:
                dp[i]=minn
        return dp[-1] if dp[-1]!=10**9+7 else -1
    
        ###############
        #LOGIC
        #amount=6
        #coins=[1,2,4]
        #    0,1,2,3,4,5,6
        #dp=[0,0,0,0,0,0,0]
        #      i->
        #j represents coin
        # for every position of dp, loop everytime the coins
        # if coin[j]==i means only 1 coin can make that amount and break
        # find the minimum by compairing the coins with j
        # dp[i-coin[j]]+1 means   
        #for amount 5
        # dp[5-1]->dp[4] +1
        # dp[5-2]->dp[3] +1
        # dp[5-3]->dp[2] +1
        #....
        #get the minn. and put it in dp[5] which will be optimal
    
