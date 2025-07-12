#https://www.naukri.com/code360/problems/inorder-traversal_3839605

from os import *
from sys import *
from collections import *
from math import *

'''
    Following is the Binary Tree node structure:
    class TreeNode:
        def __init__(self, data=0, left=None, right=None):
            self.data = data
            self.left = left
            self.right = right
'''


def getInOrderTraversal(root):
    # Write your code here.
    
    def inorder(root,result):
        if root:
            result=inorder(root.left,result)
            result.append(root.data)
            result=inorder(root.right,result)
        return result
    
    return inorder(root,[])
