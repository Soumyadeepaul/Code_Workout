#https://www.naukri.com/code360/problems/find-quadrant-of-the-coordinate_1115773

from os import *
from sys import *
from collections import *
from math import *

#Your code goes here
x,y=list(map(int,input().split()))
if x==0 and y==0:
    print("Origin")
elif y==0:
    print('x axis')
elif x==0:
    print('y axis')
elif x>0 and y>0:
    print('1st Quadrant')
elif x<0 and y>0:
    print('2nd Quadrant')
elif x<0 and y<0:
    print('3rd Quadrant')
elif x>0 and y<0:
    print('4th Quadrant')
