#https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/?envType=study-plan-v2&envId=top-interview-150

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        
        temp=root   

        while temp:
            if temp.left==None:
                temp=temp.right
            else:
                hold=temp.right
                temp.right=temp.left
                temp.left=None
                temp=temp.right
                ################
                #PLACE THE RIGHT TO THE LEAF OF RIGHT MOST of right
                t1=temp
                while t1.right!=None:
                    t1=t1.right
                t1.right=hold
        
        
