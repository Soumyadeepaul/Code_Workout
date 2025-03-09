#https://www.naukri.com/code360/problems/level-order-traversal_796002

def getLevelOrder(root):

    #   Write your code here
    if root:
        ans=[root.val]
        queue=[root]
        while queue:
            val=queue.pop(0)
            if val.left!=None:
                queue.append(val.left)
                ans.append(val.left.val)
            if val.right!=None:
                queue.append(val.right)
                ans.append(val.right.val)
        return ans
    return ['']
