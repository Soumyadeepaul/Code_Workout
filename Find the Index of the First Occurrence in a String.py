#https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        result=0
        for i in range(len(haystack)):
            if haystack[i]==needle[0]:
                result=i
                idx=1
                while idx<len(needle):
                    if i+idx<len(haystack) and needle[idx]==haystack[i+idx]:
                        idx+=1
                    else:
                        break
                if idx==len(needle):
                    return result
        return -1
