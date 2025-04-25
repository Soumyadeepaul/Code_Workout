#https://leetcode.com/problems/greatest-common-divisor-of-strings/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        l1=len(str1)
        l2=len(str2)
        if l1<l2:
            l1,l2=l2,l1
            str1,str2=str2,str1
        greatest=''
        for i in str2:
            greatest+=i
        l=len(greatest)
        while l>0:
            if l2%l==0 and l1%l==0:
                new=greatest*(l2//l)
                
                if new==str2:
                    new=greatest*(l1//l)
                    if new == str1:
                        return greatest
            greatest=''
            l=l-1
            for i in range(l):
                greatest+=str2[i]
        return greatest

