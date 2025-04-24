#https://www.naukri.com/code360/problems/rotate-array_1230543

def rotateArray(arr: list, k: int) -> list:
    # Write your code here.
    temp=[None for _ in range(len(arr))]
    k=len(arr)-k  #k=number of element from front to be rotated, here k is modified to from which position it should start replacing
    for i in range(len(arr)):
        temp[(k+i)%len(arr)]=arr[i]
    return temp
