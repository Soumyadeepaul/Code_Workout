#https://www.naukri.com/code360/problems/preorder-binary-tree_5948

from sys import stdin, setrecursionlimit
import queue

setrecursionlimit(10 ** 6)


# Following the structure used for Binary Tree
class BinaryTreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def preOrder(root):
	# Your code goes here
    
    def pre(root,stack):
        if root:
            stack.append(root.data)
            if root.left:
                stack=pre(root.left,stack)
            if root.right:
                stack=pre(root.right,stack)
        return stack
    stack=pre(root,[])
    for i in stack:
        print(i,end=' ')
