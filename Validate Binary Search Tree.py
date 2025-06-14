#https://leetcode.com/problems/validate-binary-search-tree/description/?envType=study-plan-v2&envId=top-interview-150

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        
        def inorder(root,stack):
            if root:
                stack=inorder(root.left,stack)
                stack.append(root.val)
                stack=inorder(root.right,stack)
            return stack

        stack=inorder(root,[])
        store=set()
        for i in stack:
            if i in store:
                return False
            store.add(i)
        sortedStack=sorted(stack) 
        if sortedStack==stack:
            return True
        return False
