#https://www.naukri.com/code360/problems/binary-array-sorting_985289

def sortBinaryArray(arr, n):
    # Write your code here
    i=0
    j=n-1
    while i<j:
        if arr[i]==1 and arr[j]==0:
            arr[i],arr[j]=arr[j],arr[i]
        if arr[i]==0:
            i+=1
        if arr[j]==1:
            j-=1
    return arr
