#https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/?envType=study-plan-v2&envId=top-interview-150

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        
        def tree(root,nodes,preorder,direction):
            # if len(preorder)==0:
            #     return
            if len(nodes)==0: #LEAF Node
                return
            node=TreeNode()
            val=preorder.pop(0)
            node.val=val
            leftarr=[]
            rightarr=[]
            found=0
            for i in nodes:
                if i!=val and found==0:
                    leftarr.append(i)
                elif i==val:
                    found=1
                    leftNode=1
                if i!=val and found==1:
                    rightarr.append(i)
            #print(leftarr,rightarr,val)
            if direction=='left':
                root.left=node
            else:
                root.right=node
            
            tree(node,leftarr,preorder,'left')
            tree(node,rightarr,preorder,'right')
            


        if len(preorder)==1:
            node=TreeNode()
            node.val=preorder.pop(0)
            return node
        node=TreeNode()
        val=preorder.pop(0)
        left=[]
        right=[]
        found=0
        for i in inorder:
            if i!=val and found==0:
                left.append(i)
            elif i==val:
                found=1
            if i!=val and found==1:
                right.append(i)
        node.val=val

        tree(node,left,preorder,'left')
        tree(node,right,preorder,'right')
        return node
