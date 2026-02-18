##https://leetcode.com/problems/binary-number-with-alternating-bits/description/?envType=daily-question&envId=2026-02-18


class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        prev=-1
        while(n):
            rem=n%2
            n//=2
             
            if prev==-1:
                prev=rem
            else:
                if prev!=rem :
                    prev=rem
                else:
                    return False
        return True
