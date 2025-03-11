#https://www.naukri.com/code360/problems/sort-0-1_624379

from sys import stdin

def sortZeroesAndOne(arr, n) :
    # write your code here 
    i=0
    j=n-1
    while i<j:
        if arr[i]==0:
            i+=1
        elif arr[i]==1 and arr[j]==0:
            arr[i],arr[j]=arr[j],arr[i]
        elif arr[j]==1:
            j-=1
        

