#https://leetcode.com/problems/insert-delete-getrandom-o1/description/?envType=study-plan-v2&envId=top-interview-150

import random
class RandomizedSet:

    def __init__(self):
        self.arr=set()
        return None
    def insert(self, val: int) -> bool:
        if val in self.arr:
            return False
        self.arr.add(val)
        return True

    def remove(self, val: int) -> bool:
        if val in self.arr:
            self.arr.discard(val)
            return True
        return False

    def getRandom(self) -> int:
        re=random.choice(list(self.arr))
        return re


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
