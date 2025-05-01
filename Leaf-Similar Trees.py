#https://leetcode.com/problems/leaf-similar-trees/?envType=study-plan-v2&envId=leetcode-75

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:

        # def leaf(root,queue):
        #     if root:
        #         if root.left==None and root.right==None:
        #             queue.append(root.val)
        #             return queue
        #         else:
        #             queue=leaf(root.left,queue)
        #             queue=leaf(root.right,queue)
        #     return queue
        
        # return leaf(root1,[])==leaf(root2,[])
        #####################################################
        def leaf(root,queue):
            if root:
                if root.left==None and root.right==None:
                    queue.append(root.val)
                    return queue
                else:
                    queue=leaf(root.left,queue)
                    queue=leaf(root.right,queue)
            return queue
        
        def leafcheck(root,queue):
            if root:
                if root.left==None and root.right==None:
                    if not queue:
                        queue=0
                        return queue
                    val=queue.pop(0)
                    if root.val==val:
                        return queue
                    else:
                        queue=0
                        return queue
                queue=leafcheck(root.left,queue)
                if queue==0:
                    return queue
                queue=leafcheck(root.right,queue)
                if queue==0:
                    return queue
            return queue
        
        queue=leaf(root1,[])
        #print(queue)
        queue=leafcheck(root2,queue)
        #print(queue)
        if queue==0 or len(queue)!=0:
            return False
        return True
