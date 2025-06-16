#https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/?envType=study-plan-v2&envId=top-interview-150

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root==None:
            return []
        queue=[[root,0]]
        result=[]
        prelevel=0
        leftToRight=0
        arr=[]
        while queue:
            node,level=queue.pop(0)
            
            if level!=prelevel:
                prelevel=level
                if leftToRight==1:
                    leftToRight=0
                    result.append(arr[::-1])
                else:
                    leftToRight=1
                    result.append(arr)
                arr=[]
            if node.left!=None:
                queue.append([node.left,level+1])
            if node.right!=None:
                queue.append([node.right,level+1])
            arr.append(node.val)
        if leftToRight==1:
            leftToRight=0
            result.append(arr[::-1])
        else:
            leftToRight=1
            result.append(arr)
        return result
