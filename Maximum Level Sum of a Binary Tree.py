#https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/?envType=study-plan-v2&envId=leetcode-75

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:

        queue=[[root,1]]
        result=0
        maxii= -10**9+7
        prevLevel=1
        levelSum=0
        while queue:
            node,level=queue.pop(0)
            if node.left!=None:
                queue.append([node.left,level+1])
            if node.right!=None:
                queue.append([node.right,level+1])

            if level==prevLevel:
                levelSum+=node.val
            else:
                if maxii<levelSum:
                    maxii=levelSum
                    result=level-1
                prevLevel=level
                levelSum=node.val
        if maxii<levelSum:
            maxii=levelSum
            result=level
        return result
        
