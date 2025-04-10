#https://www.naukri.com/code360/problems/check-prime_624934

n=int(input())
if n==1:
    print("NO")
else:
    prime=1
    l=[2,3,5,7,11,13,17,19,23,31,37,41,n//2]
    for i in l:
        if n>i:
            if n%i==0:
                prime=0
                print("NO")
                break
        else:
            break
    if prime==1:
        print("YES")
