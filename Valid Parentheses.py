#https://www.naukri.com/code360/problems/valid-parenthesis_795104

def isValidParenthesis(s: str) -> bool:
    # Write your code here
    stack=[]
    top=-1
    for i in s:
        if i=='{' or i=='[' or i=="(":
            stack.append(i)
            top+=1
        elif (i==')' or i=='}' or i==']') and top==-1:
            return False
        elif i==')':
            if stack[top]=='(':
                stack.pop()
                top-=1
            else:
                return False
        elif i=='}' and top!=-1:
            if stack[top]=='{':
                stack.pop()
                top-=1
            else:
                return False
        elif i==']' and top!=-1:
            if stack[top]=='[':
                stack.pop()
                top-=1
            else:
                return False
    return True
