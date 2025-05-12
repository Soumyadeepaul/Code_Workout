#https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        
        profit=[0]
        effectiveBuy=[prices[0]]
        for i in range(1,len(prices)):
            profit.append(max(profit[-1],prices[i]-effectiveBuy[-1]-fee))
            effectiveBuy.append(min(effectiveBuy[-1],prices[i]-profit[-1]))
        return profit[-1]
            
