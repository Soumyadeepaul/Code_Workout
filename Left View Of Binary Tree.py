#

# Following is the structure of Tree Node:
class BinaryTreeNode:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None
        
def leftView(root: BinaryTreeNode) -> None:
	# Write your code here.
	
    #LEVEL ORDER
    queue=[[root,0]]
    previousLevel=-1
    result=[]
    while queue:
        node,level=queue.pop(0)
        if level!=previousLevel:
            result.append(node.data)
        if node.left!=None:
            queue.append([node.left,level+1])
        if node.right!=None:
            queue.append([node.right,level+1])
        previousLevel=level
    
    for i in result:
        print(i,end=' ')
            
