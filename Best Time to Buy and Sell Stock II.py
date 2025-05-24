#https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/?envType=study-plan-v2&envId=top-interview-150
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices)==1:
            return 0

        minima=10**9+7
        profit=0
        #FIND LOCAL MINIMA AND LOCAL MAXIMA
        for i in range(len(prices)):
            if i-1==-1:
                if prices[i]<=prices[i+1]:
                    minima=prices[i]
            elif i+1<len(prices):
                if prices[i]<=prices[i+1] and prices[i]<=prices[i-1]:
                    minima=prices[i]
            if minima!=10**9+7:
                if i+1<len(prices) and prices[i]>=prices[i+1] and prices[i]>=prices[i-1]:
                    profit+=prices[i]-minima
                    minima=10**9+7
                elif i+1==len(prices) and prices[i]>minima:
                    profit+=prices[i]-minima
                    minima=10**9+7
        return profit
