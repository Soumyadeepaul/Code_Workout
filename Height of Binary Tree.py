#https://www.naukri.com/code360/problems/tree-height_4609628

# Following is the TreeNode class structure.
class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def maxDepth(root: TreeNode) -> int:
    # Write your code here.
    if root:
        return max(maxDepth(root.left),maxDepth(root.right))+1
    return 0
