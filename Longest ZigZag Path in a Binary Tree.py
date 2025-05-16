#https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/description/?envType=study-plan-v2&envId=leetcode-75
#DP
#LOGIC like Path sum 3

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        
        def postorder(root,nodes):
            if root:
                nodes=postorder(root.left,nodes)
                nodes=postorder(root.right,nodes)
                nodes.append(root)
            return nodes

        
        nodes=postorder(root,[])

        hashmap={}

        def leftRight(root,hashmap,result):
            
            left=0
            right=0
            if root.left:
                structure=hashmap[root.left]
                left=structure['right']+1
            if root.right:
                structure=hashmap[root.right]
                right=structure['left']+1
            result=max(left,right,result)
            hashmap[root]={'left':left,'right':right}
            return [result,hashmap]

        result=0
        for i in nodes:
            result,hashmap=leftRight(i,hashmap,result)
        return result

        ####################
        #LOGIC
        #postorder leaf->root
        #for every node calculate max if from it goes left,right child
        #if checked with left child, then take the value right from the child+1
        #if checked with right child, then take the valye left from the child+1
