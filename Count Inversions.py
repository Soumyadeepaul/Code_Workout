#https://www.naukri.com/code360/problems/count-inversions_615

def getInversions(arr, n):
    # write your code here !!
    #Brute force
    count=0
    for i in range(n):
        for j in range(i+1,n):
            if arr[i]>arr[j]:
                count+=1
    return count
