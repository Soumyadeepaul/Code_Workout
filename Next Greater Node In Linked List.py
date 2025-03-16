#https://www.naukri.com/code360/problems/next-greater-node-in-linked-list_1262083

from os import *
from sys import *
from collections import *
from math import *

'''
  ----Linked list Node class for reference-----
    class Node:
        def __init__(self, data):
            self.val = data
            self.next = None
            
'''

def findNextGreaterNodeList(head):

    # Write your code here
    # Return an list of integers denoting the answer
    temp=head
    ans=[]
    while temp!=None:
      data=temp.val
      checking=temp
      found=0
      while checking:
        if checking.val>data:
          found=1
          ans.append(checking.val)
          break
        checking=checking.next
      temp=temp.next
      if found==0:
        ans.append(0)
    return ans
