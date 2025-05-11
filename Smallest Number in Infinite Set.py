#https://leetcode.com/problems/smallest-number-in-infinite-set/?envType=study-plan-v2&envId=leetcode-75

from heapq import heapify, heappush, heappop
class SmallestInfiniteSet:

    def __init__(self):
        self.root=[i for i in range(1,1001)]
        self.poped=set(self.root)
        heapify(self.root)

    def popSmallest(self) -> int:
        val=heappop(self.root)
        self.poped.discard(val)
        return val

    def addBack(self, num: int) -> None:
        if num not in self.poped:
            heappush(self.root,num)
            self.poped.add(num)
        return None
        


# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)
