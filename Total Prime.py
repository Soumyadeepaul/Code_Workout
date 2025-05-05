#https://www.naukri.com/code360/problems/total-prime_1164176

from os import *
from sys import *
from collections import *
from math import *




#Write your totalPrime function here.
def totalPrime(S,E):
    count=0
    for i in range(S,E+1):
        half=i//2
        prime=1
        for j in range(2,half+1):
            if i%j==0:
                prime=0
                break
        if prime==1:
            #print(i)
            count+=1
    return count







    
#Taking S and E space seperated input.
S,E = map(int,input().split(' '))
print(totalPrime(S,E))


