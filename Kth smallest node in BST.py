#

from typing import Optional

class TreeNode:
    def __init__(self, data: int):
        self.data = data
        self.left = None
        self.right = None


def kthSmallest(root: Optional[TreeNode], k: int) -> int:
    
    # Write the code here.
    def inorder(root,stack,k):
        if root:
            stack,result=inorder(root.left,stack,k)
            if result!=None:
                return stack,result
            stack+=1
            if stack==k:
                return stack,root.data
            stack,result=inorder(root.right,stack,k)
            if result!=None:
                return stack,result
        return stack,None

    _,result=inorder(root,0,k)
    return result
            

    
