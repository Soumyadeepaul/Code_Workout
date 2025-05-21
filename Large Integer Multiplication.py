#DIVIDE AND CONQURE
#Karatsuba Algo
def lim(x,y):
    if x<10 or y<10:
        return x*y
    length=max(len(str(x)),len(str(y)))
    half=length//2
    a=x//(10**half)
    b=x%(10**half)
    c=y//(10**half)
    d=y%(10**half)
    a_c=lim(a,c)
    b_d=lim(b,d)
    factor=lim(a+b,c+d)-a_c-b_d   # ad+cb =(a+b)(c+d) -ac-bd
    return a_c*(10**(2*half))+factor*(10**half)+b_d

x=9894
y=6755
print(lim(x,y))
print(x*y)
###################################
#(x*y)
#n=length
#half=length//2
#x= a* 10**half + b
#y= c* 10**half + d

#(a* 10**half + b)(c* 10**half + d)
#(a*c)*(10**(2*half)) + (a*d + c*b) * (10**half) + (b*d)
#                          ad+cb =(a+b)(c+d) -ac-bd
