#https://www.naukri.com/code360/problems/tree-symmetricity_630426

'''

    Following is the representation for the Binary Tree Node:

    class BinaryTreeNode :
    def __init__(self, data) :
        self.data = data
        self.left = None
        self.right = None
'''

def isSymmetric(root) :
    # Write your code here.
    def symmetric(left,right):
        if not left and not right:
            return True
        if not left or not right:
            return False
        
        return left.data==right.data and symmetric(left.left,right.right) and symmetric(left.right,right.left)
    if root:
        return symmetric(root.left,root.right)
    return True
