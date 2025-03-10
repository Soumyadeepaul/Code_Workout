#https://www.naukri.com/code360/problems/stocks-are-profitable_893405

from os import *
from sys import *
from collections import *
from math import *

def maximumProfit(prices):
    # Write your code here.
    max_profit=0
    #minimum calulated yet is just compaired with the i-1 the element   TC reduced
    minimum_yet=prices[0]
    for i in range(1,len(prices)):
        val=prices[i]-min(prices[i-1],minimum_yet)
        minimum_yet=min(prices[i-1],minimum_yet)
        if val>max_profit:
            max_profit=val
    return max_profit
