#https://leetcode.com/problems/binary-tree-right-side-view/description/?envType=study-plan-v2&envId=leetcode-75

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if root==None:
            return []
        queue=[[root,0]]
        result=[]
        prevLevel=0
        prevNode=root
        while queue:
            node,level=queue.pop(0)
            if node.left!=None:
                queue.append([node.left,level+1])
            if node.right!=None:
                queue.append([node.right,level+1])
            if prevLevel!=level: #when level change
                result.append(prevNode.val)
            prevLevel=level
            prevNode=node
        result.append(prevNode.val) #append last level last node
        return result


        
