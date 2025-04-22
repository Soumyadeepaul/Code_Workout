#https://leetcode.com/problems/find-the-pivot-integer/description/

class Solution:
    def pivotInteger(self, n: int) -> int:
        #Linear Search
        # valLeft=0
        # valRight=(n*(n+1))//2
        # for i in range(1,n+1):
        #     valLeft+=i
        #     if valLeft==valRight:
        #         return i
        #     valRight-=i
        # return -1

        #######################

        #Binary Search
        if n==1:
            return 1
        n1=n
        mid=n1//2
        while n1>0:
            valLeft=(mid*(mid+1))//2
            valRight=((n*(n+1))//2)-valLeft+mid
            n1=n1//2   #to shift the mid
            if valLeft<valRight:
                mid+=n1//2+1
            elif valLeft>valRight:
                mid-=n1//2+1
            else:
                return mid
        return -1
