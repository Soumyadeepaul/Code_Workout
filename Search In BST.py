#https://www.naukri.com/code360/problems/search-in-bst_1402878

'''
class TreeNode:

    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
'''

from typing import List

def searchInBST(root, x):
    # Write your code here.
    if root:
        if root.data==x:
            return True
        elif root.data>x:
            return searchInBST(root.left,x)
        return searchInBST(root.right,x)
    else:
        return False
