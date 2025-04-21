#

from os import *
from sys import *
from collections import *
from math import *

def titleToNumber(stringStr):

    # Write your code here
    # Return number
    l=len(stringStr)
    position=1 #it is maintained from last index
    idx=65 #ASCII of A
    toBeAdded=26 #when traversing from right to left, we have to use it
    value=0 #result
    leftOut=0 # let ABA, leftout is used for A to Z ->    26
              #                             AA to ZZ ->26*26 
              # the summation of the lesser length string will be added

    #FOR ABA->length of 3's calculation is made like from AAA to ABA
    #then adding A to Z and AA to ZZ's value

    #starting from end alphabet
    for i in stringStr[::-1]:

        #get the difference like A-A=0+1
        val=ord(i)-65+1

        #if last index, the just add the difference like for A add 1
        if position==1:
            value+=val
        else:
            #for ABA's B which is (26)*1
            #for CBA's C which is (26*26)*2
            value+=toBeAdded*(val-1)
            leftOut+=toBeAdded  #Storing the leftout value at same time
            toBeAdded*=26 #as position increase addition value gets multiplied with 26
        position+=1
    # CBB  = 2->+(26*1)->B+(26*26*2)->C   +    26->ofLength1+(26*26)->ofLength2
    return value+leftOut
