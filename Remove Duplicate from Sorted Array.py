#https://www.naukri.com/code360/problems/remove-duplicates-from-sorted-array_1102307

def removeDuplicates(arr,n):
    # Write your code here.
    i=0
    while i<len(arr)-1:
        if arr[i]==arr[i+1]:
            arr.pop(i)
            i-=1
        i+=1
    return len(arr)
