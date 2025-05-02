#https://leetcode.com/problems/decode-string/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def decodeString(self, s: str) -> str:
        stack=[] #to store alpha and backet
        values=[] #to store numbers
        opening=0
        i=0
        while i<len(s):#traverse string
            if s[i]=='[': #is open backet, append and count++
                opening+=1
                stack.append(s[i])
            elif s[i]==']': #if closeing backet
                curr='' #string creation
                while stack[-1]!='[': #pop till opening backet found
                    strr=stack.pop()
                    curr=strr+curr #create its string
                stack.pop()
                val=values.pop() #get its value

                curr=curr*int(val) #get the string
                while curr!='': #loop the string and append to the stack
                    stack.append(curr[0])
                    curr=curr[1:]
                opening-=1 #opeing backet get less by 1
            elif s[i] in '0123456789':
                val=s[i]
                while s[i+1] in '0123456789': #if value >9
                    val+=s[i+1]
                    i+=1
                values.append(val)
            else:
                stack.append(s[i]) #if alpha
            i+=1
        result=''.join(stack)
        return result
#a2[b2[c]]
#stack=[a]
#[a,[,b]
#[a,[,b,[,c]
#[a,[,b,c,c] when we get close backet, find open backet, and push back into the stack
#[a,b,c,c,b,c,c] -> ans        
