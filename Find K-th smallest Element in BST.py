#https://www.naukri.com/code360/problems/find-k-th-smallest-element-in-bst_1069333

from os import *
from sys import *
from collections import *
from math import *

'''
  ----Binary tree node class for reference-----
    class BinaryTreeNode:
        def __init__(self, data):
            self.data = data
            self.left = None
            self.right = None

'''

def kthSmallest(root, k):

    # Write your code here
    # Return the value of 'k-th' smallest node.
    def small(root,k,arr=[]):
      if root:
        small(root.left,k,arr)
        k-=1
        arr.append(root.data)
        if k!=0:
          small(root.right,k,arr)

      return arr
    arr=small(root,k)
    try:
      return arr[k-1]
    except:
      return -1

      
