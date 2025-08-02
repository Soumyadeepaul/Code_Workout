#

def longestSubSeg(arr, n, k):
    #   Write your code here.
    
    result=0
    window=[]
    for i in range(n):
        if arr[i]==1:
            window.append(arr[i])
        else:
            if k>0:
                window.append(arr[i])
                k-=1
            else:
                while window:
                    val=window.pop(0)
                    if val==0:
                        k+=1
                        break
                window.append(arr[i])
                k-=1
        #print(window,k)
        result=max(result,len(window))
    return result
