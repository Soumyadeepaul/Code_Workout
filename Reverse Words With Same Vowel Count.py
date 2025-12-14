#https://leetcode.com/contest/weekly-contest-480/problems/reverse-words-with-same-vowel-count/description/


class Solution:
    def reverseWords(self, s: str) -> str:
        store=s.split(" ")
        vowel=['a','e','i','o','u']
        count=0
        for i in store[0]:
            if i in vowel: count+=1
        for i in range(1,len(store)):
            c=0
            for j in store[i]:
                if j in vowel: c+=1
            if c==count:
                store[i]=store[i][::-1]
        return " ".join(store)
