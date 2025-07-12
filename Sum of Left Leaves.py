#https://leetcode.com/problems/sum-of-left-leaves/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        
        def leaf(root,side,summ):
            if root:
                if root.left==None and root.right==None:
                    if side=='l':
                        summ+=root.val
                summ=leaf(root.left,'l',summ)
                summ=leaf(root.right,'r',summ)
            return summ
        
        return leaf(root,'',0)
