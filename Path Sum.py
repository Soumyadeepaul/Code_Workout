#https://leetcode.com/problems/path-sum/?envType=study-plan-v2&envId=top-interview-150

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:

        def order(root,stack,results):
            if root:
                if root.left==None and root.right==None:
                    stack.append(root.val)
                    results.append(sum(stack))
                    stack.pop() #LEAF POP
                    return results
                stack.append(root.val)
                results=order(root.left,stack,results)
                results=order(root.right,stack,results)
                stack.pop()
            return results
        
        results=order(root,[],[])
        return True if targetSum in results else False
