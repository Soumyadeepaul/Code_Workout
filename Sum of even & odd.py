#https://www.naukri.com/code360/problems/sum-of-even-odd_624650

if __name__ == "__main__":
    n=int(input())
    even=0
    odd=0
    while n:
        remainder=n%10
        n=n//10
        if remainder%2==0:
            even+=remainder
        else:
            odd+=remainder
    print(even," ",odd)
