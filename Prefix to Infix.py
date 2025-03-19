#https://www.naukri.com/code360/problems/prefix-to-infix_1215000

def prefixToInfixConversion(s: str) -> str:
    # Write your code here.
    stack=[]
    for i in s[::-1]:
        if i=='+' or i=='-' or i=='*' or i=='/':
            val2=stack.pop()
            val1=stack.pop()
            val=")"+val1+i+val2+"("
            stack.append(val)
        else:
            stack.append(i)
    return stack[0][::-1]
