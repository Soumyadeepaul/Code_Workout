#https://www.naukri.com/code360/problems/number-of-vehicles_893284

from os import *
from sys import *
from collections import *
from math import *

def numberOfVehicles(districtCount, alpha1, alpha2, alpha3, alpha4, dig1, dig2, dig3, dig4):
    # Write your code here.
    
    alpha1_range=abs(ord(alpha1)-ord(alpha2))+1
    alpha3_range=abs(ord(alpha3)-ord(alpha4))+1
    return districtCount*alpha1_range*alpha3_range*(dig1+1)*(dig2+1)*(dig3+1)*(dig4+1)
