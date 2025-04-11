#https://www.naukri.com/code360/problems/minimum-depth-in-a-binary-tree_696332

from os import *
from sys import *
from collections import *
from math import *

'''************************************************************

    Following is the Tree node structure
    
    class TreeNode:
        TreeNode(val):
            this.val = val
            left = None
            right = None

***********************************************************'''
####################
#BFS
####################
def minDepth(root):

    # write your code here.
    queue=[root]
    position=[1] #level counting 
    while queue:
        node=queue.pop(0)
        p=position.pop(0)
        if node:
            if node.left==None and node.right==None:
                return p
            else:
                if node.left:
                    queue.append(node.left)
                    position.append(p+1)  #maintaining level
                if node.right:
                    queue.append(node.right)
                    position.append(p+1)
    return 0
            
