#https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/description/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        binaryA=''
        binaryB=''
        binaryC=''
        lenc=0
        while c:
            binaryC=str(c%2)+binaryC
            c//=2
            lenc+=1
        ####################
        lena=0
        while a:
            binaryA=str(a%2)+binaryA
            a//=2
            lena+=1
        
        ######################
        lenb=0
        while b:
            binaryB=str(b%2)+binaryB
            b//=2
            lenb+=1
        if lenc==lena==lenb:
            maximum=lenc
        else:
            maximum=max(lenc,lena,lenb)
            #for A
            extra='0'*(maximum-lena)
            binaryA=extra+binaryA

            #for B
            extra='0'*(maximum-lenb)
            binaryB=extra+binaryB

            #for C
            extra='0'*(maximum-lenc)
            binaryC=extra+binaryC
        count=0
        for i in range(maximum):
            val=binaryC[i]
            if val=='0':
                if binaryA[i]=='0' and binaryB[i]=='0':
                    pass
                else:
                    if binaryA[i]=='1' and binaryB[i]=='1':
                        count+=1
                    count+=1
            else:
                if binaryA[i]=='0' and binaryB[i]=='0':
                    count+=1
        return count
