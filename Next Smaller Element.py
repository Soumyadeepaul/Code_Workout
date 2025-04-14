#https://www.naukri.com/code360/problems/next-smaller-element_1112581

def nextSmallerElement(arr,n):
    # Write your code here.
    
    stack=[arr[n-1]]
    result=[-1]
    i=n-2
    while i>=0:
        if arr[i]>arr[i+1]:
            result.insert(0,arr[i+1])
            stack.append(arr[i])
        else:
            calculated=0
            while len(stack)>0:
                val=stack.pop()
                if arr[i]<=val:
                    pass
                else:
                    calculated=1
                    stack.append(val)
                    stack.append(arr[i])
                    result.insert(0,val)
                    break
            if calculated==0:
                stack.append(arr[i])
                result.insert(0,-1)
        i-=1
    return result


