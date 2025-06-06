#https://leetcode.com/problems/same-tree/?envType=study-plan-v2&envId=top-interview-150

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        def tree(p,q):
            if p and q:
                if p.val!=q.val:
                    return False
                return tree(p.left,q.left) and tree(p.right,q.right)
            elif p==None and q==None:
                return True
            else:
                return False
        return tree(p,q)
