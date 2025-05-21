#http://leetcode.com/problems/longest-substring-without-repeating-characters/description/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        window=[]
        length=0
        for i in s:
            if i not in window:
                window.append(i)
            else:
                while window:
                    if i!=window[0]:
                        window.pop(0)
                    elif i==window[0]:
                        break
                window.pop(0)
                window.append(i)
            length=max(length,len(window))
        return length
