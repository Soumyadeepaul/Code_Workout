#https://leetcode.com/problems/path-sum-iii/?envType=study-plan-v2&envId=leetcode-75

#DP

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        #Post order
        def findNodes(root,nodes):
            if root:
                nodes=findNodes(root.left,nodes)
                nodes=findNodes(root.right,nodes)
                nodes.append(root)
            return nodes

        nodes=findNodes(root,[])
        hashmap={}
        #left node -> root node

        def countPath(root,hashmap,targetSum,result):
            # if root.left==None and root.right==None:
            #     hashmap[root]=[root.val]
            #     return [result,hashmap]
            
            stack=[root.val]
            if root.val==targetSum:
                result+=1
            if root.left!=None:
                values=hashmap[root.left]
                for i in values:
                    target=root.val+i
                    if target==targetSum:
                        result+=1
                    stack.append(target)
            if root.right!=None:
                values=hashmap[root.right]
                for i in values:
                    target=root.val+i
                    if target==targetSum:
                        result+=1
                    stack.append(target)
            hashmap[root]=stack
            return [result,hashmap]
        result=0
        for i in nodes:
            result,hashmap=countPath(i,hashmap,targetSum,result)
        return result

        #############################################
        #LOGIC
        #    5
        #   / \
        #  -1 2
        #  /\
        # 3  1

        #Postorder [3,1,-1,2,5]
        #parent's leafs will always come first
        # hashmap={3:[3]}
        #hashmap={3:[3],1:[1]}
        #now when -1 will come... its left and right calculation is stored in hashmap
        #left -1+3
        #right -1+1
        #{-1:[-1,4,0]}

        #SAME FOR Right subtree

        #and root can use the left and right value, without recalculating every node
                

        
