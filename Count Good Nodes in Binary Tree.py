#https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/?envType=study-plan-v2&envId=leetcode-75

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        
        def counter(root,stack,rootValue,count):
            if root:
                if root.val>=rootValue:
                    isOK=1
                    for i in stack: #maintained stack to check
                        if i<=root.val:
                            pass
                        else:
                            isOK=0
                            break
                    if isOK==1:
                        count+=1
                stack.append(root.val) #stack append new node
                count=counter(root.left,stack,rootValue,count)
                count=counter(root.right,stack,rootValue,count)
                stack.pop() #backtrack to remove the node added
            return count
        
        return counter(root,[],root.val,0)
