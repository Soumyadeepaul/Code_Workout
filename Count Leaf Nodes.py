#https://www.naukri.com/code360/problems/count-leaf-nodes_893055

'''
    Following is the Binary Tree Node class structure.
    class BinaryTreeNode:
        def __init__(self, data):
            self.data = data
            self.left = None
            self.right = None
'''

def noOfLeafNodes(root):
    # Write your code here.
    if root:
        if root.left==None and root.right==None:
            return 1
        elif root.left and root.right==None:
            return noOfLeafNodes(root.left)
        elif root.right and root.left==None:
            return noOfLeafNodes(root.right)
        else:
            return noOfLeafNodes(root.left)+noOfLeafNodes(root.right)
