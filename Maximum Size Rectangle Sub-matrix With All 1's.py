#https://www.naukri.com/code360/problems/maximum-size-rectangle-sub-matrix-with-all-1-s_893017

from sys import stdin, stdout, setrecursionlimit

def maximalAreaOfSubMatrix(mat, N, M):

    # Write your code here.
    
    #Maximum size Rectangle in Histogram
    def sizeRectangleHistogram(arr):
        maximum=0
        curr=0 #every element be the height and traverse to and fro to find continious same or more height, and calucate width
        while curr<len(arr):
            prev=curr-1
            nextt=curr+1
            width=1
            while prev>-1 and arr[prev]>=arr[curr]:
                width+=1
                prev-=1
            while nextt<len(arr) and arr[nextt]>=arr[curr]:
                width+=1
                nextt+=1
            maximum=max(maximum,width*arr[curr])
            curr+=1
        return maximum
    arr=[0 for _ in range(M)]
    result=0
    for i in mat:
        arr_pos=0
        for j in i:
            if j==0:
                arr[arr_pos]=0 #if 0, then reduce the height of histogram to 0
            else:
                arr[arr_pos]+=j
            arr_pos+=1
        result=max(result,sizeRectangleHistogram(arr))
    return result


























# Taking input using fast I/0
def takeInput():
    N, M = list(map(int, stdin.readline().strip().split(" ")))
    mat = list()
    for i in range(N):
        mat.append(list(map(int, stdin.readline().strip().split(" "))))

    return N, M, mat


tc = int(input())
while tc > 0:
    N, M, mat = takeInput()
    ans = maximalAreaOfSubMatrix(mat, N, M)
    stdout.write(str(ans) + "\n")
    tc -= 1
