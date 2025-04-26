#https://leetcode.com/problems/string-compression/description/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def compress(self, chars: List[str]) -> int:
        chars.append('')
        i=1
        store=chars[0]
        count=1
        counts=[]
        while i<len(chars):
            if chars[i]==store:
                chars.pop(i)
                count+=1
            else:
                store=chars[i]
                counts.append(str(count))
                count=1
                i+=1
        i=1
        while i<len(chars):
            val=counts.pop(0)
            if val!='1' and len(val)>0:
                while val:
                    c=val[0]
                    val=val[1:]
                    chars.insert(i,c)
                    i+=1
            i+=1
        chars.pop()
        return len(chars)
        
