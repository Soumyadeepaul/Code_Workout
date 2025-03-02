#https://www.naukri.com/code360/problems/reverse-bits_2181102

def reverseBits(n):
    # Write your code here.
    if n==0:
        return 0
    bits=[]
    while n:
        bit=n%2
        bits.append(bit)
        n=n//2
    result=0
    present=1
    lenn=len(bits)
    for i in range(lenn,32):
        present=present*2
    for i in range(len(bits)-1,-1,-1):
        result=result+bits[i]*present
        present=present*2
    return result

