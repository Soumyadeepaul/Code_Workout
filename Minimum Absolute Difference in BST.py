#https://leetcode.com/problems/minimum-absolute-difference-in-bst/?envType=study-plan-v2&envId=top-interview-150

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        
        def inorder(root,stack,minimum):
            if root:
                stack,minimum=inorder(root.left,stack,minimum)
                stack.append(root.val)
                if len(stack)>1:
                    minn=abs(root.val-stack[-2])
                    minimum=min(minn,minimum)
                    stack.pop(0)
                stack,minimum=inorder(root.right,stack,minimum)
            return [stack,minimum]
        
        stack,minimum=inorder(root,[],10**9+7)
        return minimum
