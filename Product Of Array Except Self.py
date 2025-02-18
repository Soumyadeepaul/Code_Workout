#https://www.naukri.com/code360/problems/product-of-array-except-self_630271


from sys import stdin

def getProductArrayExceptSelf(arr, n) :
    #Your code goes here
    value=1
    zero_exsist=0
    for i in arr:
        if i!=0:
            value*=i
        else:
            zero_exsist+=1
    if zero_exsist>1:
        for i in range(n):
            arr[i]=0
        return arr

    for i in range(n):
        if arr[i]!=0:
            if zero_exsist==0:
                arr[i]=(value//arr[i])%(1000000007)
            else:
                arr[i]=0
        else:
            arr[i]=value%(10**9+7)
    return arr








































def takeInput() :
    n = int(stdin.readline().rstrip())

    if n == 0 :
        return list(), 0

    arr = list(map(int, stdin.readline().rstrip().split(" ")))
    return arr, n

def printList(arr, n) :
    for i in range(n) :
        print(arr[i], end = " ") 
    print()


#main
t = int(stdin.readline().rstrip())

while t > 0 :

    arr, n = takeInput()
    product = getProductArrayExceptSelf(arr, n)
    printList(product, n)
    
    t -= 1
