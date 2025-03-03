#https://www.naukri.com/code360/problems/two-stacks_983634

from os import *
from sys import *
from collections import *
from math import *

# Complete this class
class TwoStack:
    def __init__(self,s):
        self.stack1=[]
        self.stack2=[]
        self.s=s

    # Push function for the first stack
    def push1(self, val):
        if len(self.stack1)+len(self.stack2)<self.s:
            self.stack1.append(val)
        

    # Push function for the second stack
    def push2(self, val):
        if len(self.stack1)+len(self.stack2)<self.s:
            self.stack2.append(val)
    # Pop function for the first stack
    def pop1(self):
        if self.stack1:
            return self.stack1.pop()
        return -1
    # Pop function for the second stack
    def pop2(self):
        if self.stack2:
            return self.stack2.pop()
        return -1
        
