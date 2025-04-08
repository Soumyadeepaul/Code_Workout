#https://www.naukri.com/code360/problems/median-in-a-stream_975268
##################
#TLE
##################

def findMedian(arr, n):

    # Write your code here
    result=[]
    stack=[]
    mid=0
    def  stackSort(stack,val):
        if stack:
            top=stack.pop()
            if top>val:
                stackSort(stack,val)
                stack.append(top)
            else:
                stack.append(top)
                stack.append(val)
        else:
            stack.append(val)
        return stack
    for i in range(1,len(arr)+1):
        stack=stackSort(stack,arr[i-1])
        if i%2!=0:
            result.append(stack[mid])
        else:
            mid1=mid
            mid2=mid+1
            result.append((stack[mid1]+stack[mid2])//2)
            #incase of odd length mid increases
            mid+=1
    return result
