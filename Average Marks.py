#https://www.naukri.com/code360/problems/average-marks_893183
from os import *
from sys import *
from collections import *
from math import *

def averageMarks(firstLetterOfName, m1, m2, m3):

    # Write your code here
    # Return a pair<char, int>  denoting the answer
    res=(m1+m2+m3)//3
    return [firstLetterOfName,res]
