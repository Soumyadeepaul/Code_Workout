#https://www.naukri.com/code360/problems/reverse-of-a-number_624652

#Write Your Code Here
n=int(input())
result=0
while n:
    re=n%10
    n=n//10
    result=result*10+re
print(result)
