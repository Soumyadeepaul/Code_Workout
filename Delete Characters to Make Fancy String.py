#https://leetcode.com/problems/delete-characters-to-make-fancy-string/?envType=daily-question&envId=2025-07-21


class Solution:
    def makeFancyString(self, s: str) -> str:
        stack=[]
        previous=''
        count=0
        for i in s:
            if i!=previous:
                stack.append(i)
                count=1
                previous=i
            else:
                if count==2:
                    pass
                else:
                    stack.append(i)
                    count+=1
        return ''.join(stack)
