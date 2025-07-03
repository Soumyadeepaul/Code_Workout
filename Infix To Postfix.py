#

def infixToPostfix(exp: str) -> str:
    # Write your code here.
    stack=[]
    ans=''
    for i in range(len(exp)):
        # print(ans)
        # print(stack)
        if exp[i] in '+-*/^':
        
            if exp[i]=='+':
                while stack:
                    val=stack.pop()
                    
                    if val=='(':
                        stack.append("(")
                        break
                    ans+=val
                stack.append("+")
            if exp[i]=='-':
                while stack:
                    
                    val=stack.pop()
                    if val=='(':
                        stack.append('(')
                        break
                    ans+=val
                stack.append("-")
            if exp[i]=='*':
                while stack:
                    val=stack.pop()
                    if val in '-+(':
                        stack.append(val)
                        break
                    
                    else:
                        ans+=val
                stack.append("*")
            if exp[i]=='/':
                while stack:
                    val=stack.pop()
                    if val in '-+(':
                        stack.append(val)
                        break
                    
                    else:
                        ans+=val
                stack.append("/")
            if exp[i]=='^':
                while stack:
                    val=stack.pop()
                    if val in '-+*/(':
                        stack.append(val)
                        break
                    else:
                        ans+=val
                stack.append("^")
            
        elif exp[i] == ')':
            while stack:
                val=stack.pop()
                if val=='(':
                    break
                else:
                    ans+=val
        elif exp[i]=='(':
            stack.append(exp[i])
        else:
            ans+=exp[i]
    while stack:
        val=stack.pop()
        ans+=val
    return ans
