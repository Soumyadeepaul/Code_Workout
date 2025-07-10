#

# BinaryTreeNode class for reference.
class BinaryTreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def maxSubtreeAverage(root):
    # Write your code here.
    def order(root,stack,side,avg):
        if root:
            #IF LEFT side..... then have the stack intact
            if side=='l':
                stack,avg=order(root.left,stack,'l',avg)
            #If right then left... get it a new stack
            else:
                stack,avg=order(root.left,[],'l',avg)
            #Right will always ahave new stack
            stack2,avg=order(root.right,[],'r',avg)

            #create left + right + root
            stack.extend(stack2)
            stack.append(root.data)

            
            a=sum(stack)/len(stack)
            avg=max(a,avg)
        return stack,avg
    _,avg=order(root,[],'',-10**9+7)
    return avg
