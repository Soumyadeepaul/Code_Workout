########################################
TLE
########################################
from os import *
from sys import *
from collections import *
from math import *

class TreeNode:
    def __init__(self, data) :
        self.data = data
        self.left = None
        self.right = None

    def __del__(self):
        if self.left:
            del self.left
        if self.right:
            del self.right
def mergeBST(root1, root2):
	# Write your code here.

    #find position in root1
    def position(root,node):
        if root:
            if root.data>node.data:
                if root.left:
                    position(root.left,node)
                else:
                    root.left=node  
            else:
                if root.right:
                    position(root.right,node)
                else:
                    root.right=node
    def inorder(root,temp):
        if root:
            inorder(root.left,temp)
            inorder(root.right,temp)
            position(temp,root)
            root.left=None
            root.right=None
    temp=root1
    inorder(root2,temp)
    return root1 
            
