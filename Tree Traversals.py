#https://www.naukri.com/code360/problems/tree-traversal_981269

from sys import *
from collections import *
from math import *

# Following is the Binary Tree node structure:
class BinaryTreeNode :
    def __init__(self, data) :
        self.data = data
        self.left = None
        self.right = None

def getTreeTraversal(root):
    # Write your code here.
    inorder=[]
    preorder=[]
    postorder=[]
    root1=root
    root2=root
    def inorderNode(root):
        if root:
            inorderNode(root.left)
            inorder.append(root.data)
            inorderNode(root.right)

    def preorderNode(root):
        if root:
            preorder.append(root.data)
            preorderNode(root.left)
            preorderNode(root.right)
    
    def postorderNode(root):
        if root:
            postorderNode(root.left)
            postorderNode(root.right)
            postorder.append(root.data)
    inorderNode(root1)
    postorderNode(root)
    preorderNode(root2)

    return [inorder,preorder,postorder]
