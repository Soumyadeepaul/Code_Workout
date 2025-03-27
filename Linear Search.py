#https://www.naukri.com/code360/problems/linear-search_624470

from sys import stdin

def linearSearch(arr, n, val) :
    #write your code logic 
    for i in range(n):
        if arr[i]==val:
            return i
    return -1
