#https://www.naukri.com/code360/problems/find-peak-element_1081482
#LINEAR SEARCH
def findPeakElement(arr: [int]) -> int:
    # Write your code here
    for i in range(len(arr)):
        if (i==0 and arr[i]>arr[i+1]) or (i==len(arr)-1 and arr[i]>arr[i-1]) or (i!=0 and i!=len(arr)-1 and arr[i]>arr[i+1] and arr[i]>arr[i-1]):
            return i

###########################################################################################################################
#BINARY SEARCH
#https://leetcode.com/problems/find-peak-element/description/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def findPeakElement(self, arr: List[int]) -> int:
        start=0
        end=len(arr)-1
        while start<=end:
            mid=start+(end-start)//2
            peak=arr[mid]
            #####
            if mid-1>-1 and mid+1<len(arr):
                if arr[mid-1]<peak and arr[mid+1]<peak: #CHECK LEFT RIGHT
                    return mid
                elif arr[mid-1]>peak:
                    end=mid-1
                elif arr[mid+1]>peak:
                    start=mid+1
            #####
            elif mid+1<len(arr): #IF RIGHT SIDE PRESENT
                if arr[mid+1]<peak:
                    return mid
                elif arr[mid+1]>peak:
                    start=mid+1
            #####
            elif mid-1>-1:#IF LEFT SIDE PRESENT
                if arr[mid-1]<peak:
                    return mid
                elif arr[mid-1]>peak:
                    end=mid-1
            #####
            else: # IF SINGLE ELEMENT
                return mid
