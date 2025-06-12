#https://leetcode.com/problems/sum-root-to-leaf-numbers/?envType=study-plan-v2&envId=top-interview-150

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        

        def order(root,stack,string):
            if root:
                if root.left==None and root.right==None:
                    string+=str(root.val)
                    stack.append(int(string))
                    string=string[:-1]
                    return [stack,string]

                string+=str(root.val)
                stack,string=order(root.left,stack,string)
                stack,string=order(root.right,stack,string)
                string=string[:-1]
            return [stack,string]
        
        if root:
            stack,string=order(root,[],'')
            return sum(stack)
        return 0
