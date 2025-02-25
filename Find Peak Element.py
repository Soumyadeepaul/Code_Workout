#https://www.naukri.com/code360/problems/find-peak-element_1081482

def findPeakElement(arr: [int]) -> int:
    # Write your code here
    for i in range(len(arr)):
        if (i==0 and arr[i]>arr[i+1]) or (i==len(arr)-1 and arr[i]>arr[i-1]) or (i!=0 and i!=len(arr)-1 and arr[i]>arr[i+1] and arr[i]>arr[i-1]):
            return i
