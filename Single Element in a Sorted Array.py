#https://www.naukri.com/code360/problems/unique-element-in-sorted-array_1112654

def singleNonDuplicate(arr):
    # Write your code here
    if len(arr)==1:
        return arr[0]
    i=1
    while i<len(arr)-1:
        
        if arr[i]==arr[i+1]:
            i+=2
        elif arr[i]==arr[i-1]:
            i+=1
        elif arr[i]!=arr[i-1] and arr[i]!=arr[i+1]:
            return arr[i]
    if arr[0]!=arr[1]:
        return arr[0]
    return arr[len(arr)-1]
            

