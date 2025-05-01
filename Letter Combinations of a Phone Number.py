#https://leetcode.com/problems/letter-combinations-of-a-phone-number/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        hashmap={'2':['a','b','c'],'3':['d','e','f'],
                 '4':['g','h','i'],'5':['j','k','l'],
                 '6':['m','n','o'],'7':['p','q','r','s'],
                 '8':['t','u','v'],'9':['w','x','y','z']}
        i=0
        ans=[]
        while i<len(digits):
            digit=digits[i]
            values=hashmap[digit]
            if ans:
                new=[]
                while ans:
                    val=ans.pop()
                    for j in values:
                        new.append(val+j)
                ans.extend(new)
            else:
                ans.extend(values)
            i+=1
        return ans
