#https://leetcode.com/problems/average-of-levels-in-binary-tree/description/?envType=study-plan-v2&envId=top-interview-150

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        queue=[[root,0]]
        result=[]
        prev=0
        stack=[]
        while queue:
            node,level=queue.pop(0)
            if level!=prev:
                result.append(sum(stack)/len(stack))
                prev=level
                stack=[node.val]
            else:
                stack.append(node.val)
            if node.left:
                queue.append([node.left,level+1])
            if node.right:
                queue.append([node.right,level+1])
        result.append(sum(stack)/len(stack))
        return result
