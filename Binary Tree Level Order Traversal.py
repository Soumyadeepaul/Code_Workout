#https://leetcode.com/problems/binary-tree-level-order-traversal/description/?envType=study-plan-v2&envId=top-interview-150

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root==None:
            return []
        queue=[[root,0]]
        result=[]

        stack=[]
        prevLevel=0
        while queue:
            node,level=queue.pop(0)
            if prevLevel==level:
                stack.append(node.val)
            else:
                result.append(stack)
                stack=[node.val]
                prevLevel=level #LEVEL UPDATE previous level
            if node.left!=None:
                queue.append([node.left,level+1])
            if node.right!=None:
                queue.append([node.right,level+1])
        result.append(stack) #Last level
        return result
