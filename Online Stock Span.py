#https://leetcode.com/problems/online-stock-span/description/?envType=study-plan-v2&envId=leetcode-75

class StockSpanner:

    def __init__(self):
        self.arr=[]
        self.dp=[]

    def next(self, price: int) -> int:
        if not self.dp:
            self.dp.append(1)
            self.arr.append(price)
            return 1
        i=len(self.arr)-1
        summ=1
        while i>-1:
            if self.arr[i]<=price:
                span=self.dp[i]
                summ+=span
                i=i-span
            else:
                break
        self.dp.append(summ)
        self.arr.append(price)
        return summ


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)
