#https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/?envType=study-plan-v2&envId=leetcode-75

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        def preorder(root,stack,p,q): #SEARCH p or q from left -> right (Preorder) when found return stack... stack is the parent nodes from top to down till the node
            if root:
                # check the node
                if root.val==p.val:
                    p.val=-1
                    return [stack,p,q]
                if root.val==q.val:
                    q.val=-1
                    return [stack,p,q]
                # If the node != value... insert the node in the stack
                stack.append([root,root.val])

                #move towards left child
                if root.left:
                    stack,p,q=preorder(root.left,stack,p,q)
                #if found ->return stack
                if p.val==-1 or q.val==-1:
                    return [stack,p,q]
                #if not found in left, remove the parent node from the stack
                #Becoz now we r going to check in right child
                #Intution says.. there is no possiblity left to find the value in left from it
                stack.pop()

                #move to right
                if root.right:
                    stack,p,q=preorder(root.right,stack,p,q)
            return [stack,p,q]


        def search(root,x,found):
            if root:
                if root.val==x.val:
                    return 1
                found=search(root.left,x,found)
                if found==1:
                    return 1
                found=search(root.right,x,found)
            return found

        #Keep the value preserved
        pCopy=p.val
        qCopy=q.val

        #function call to find the node and stack
        stack,p,q=preorder(root,[],p,q)

        #reverse the stack because we need to find from lower lever to higher level
        stack=stack[::-1]


        found=0

        #If p was found
        if p.val==-1:
            #The stack's node always check from right child of it
            #From right child check for the partner's value
            for i in stack:
                if i[0].right:
                    found=search(i[0].right,q,found)
                    #If found return the stacks node
                    if found==1:
                        return i[0]

        elif q.val==-1:
            #The stack's node always check from right child of it
            #From right child check for the partner's value
            for i in stack:
                if i[0].right:
                    found=search(i[0].right,p,found)
                    if found==1:
                        return i[0]
        
        #If the partner value was not found....

        #Then it is sure that it will be any of the child or grandchild node from it.
        if p.val==-1:
            p.val=pCopy
            return p
        else:
            q.val=qCopy
            return q

    #############################
    #Step 1: search for p or q in preorder, and prepare an parent stack
    #Step 2: search from rest of the nodes except from the node where value was found
    #        it is performed using stack nodes and always find from the right child of stack nodes
    #Step 3: if not found from the stack nodes children
    #Step 4: the partner value is a part of its child node... so return the node
