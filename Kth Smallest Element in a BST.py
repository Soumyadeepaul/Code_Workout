#https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/?envType=study-plan-v2&envId=top-interview-150

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        
        def count(root,c,stack):
            if root:
                c+=1
                c,stack=count(root.left,c,stack)
                stack.append(root.val)
                c,stack=count(root.right,c,stack)
            return [c,stack]
        
        

        c,order=count(root.left,0,[])
        if c>=k:
            return order[k-1]
        else:
            if k==c+1:
                return root.val
            else:
                k=k-(c+1)
                c,order=count(root.right,0,[])
                return order[k-1]

                
