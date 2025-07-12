#https://www.naukri.com/code360/problems/top-view-of-the-tree_799401

from os import *
from sys import *
from collections import *
from math import *

from sys import stdin, setrecursionlimit
from queue import Queue
setrecursionlimit(10**7)

# Following is the TreeNode class structure:
class BinaryTreeNode:
    def __init__(self, data):
        self.val = data
        self.left = None
        self.right = None

def getTopView(root):
    # Write your code here.
    
    root.val=[root.val,0]
    queue=[root]
    found=[0,0]
    result=[root.val[0]]

    while queue:
        root=queue.pop(0)
        node,value=root.val
        if value<found[0]:
            result.insert(0,node)
            found[0]=value
        elif value>found[1]:
            result.append(node)
            found[1]=value
        if root.left:
            root.left.val=[root.left.val,value-1]
            queue.append(root.left)
        if root.right:
            root.right.val=[root.right.val,value+1]
            queue.append(root.right)
    return result



            




# Taking input.
def takeInput():

    arr = list(map(int, stdin.readline().strip().split(" ")))

    rootData = arr[0]

    n = len(arr)

    if(rootData == -1):
        return None

    root = BinaryTreeNode(rootData)
    q = Queue()
    q.put(root)
    index = 1
    while(q.qsize() > 0):
        currentNode = q.get()

        leftChild = arr[index]

        if(leftChild != -1):
            leftNode = BinaryTreeNode(leftChild)
            currentNode.left = leftNode
            q.put(leftNode)

        index += 1
        rightChild = arr[index]

        if(rightChild != -1):
            rightNode = BinaryTreeNode(rightChild)
            currentNode .right = rightNode
            q.put(rightNode)

        index += 1

    return root

# Printing the tree nodes.
def printAns(ans):
    for x in ans:
        print(x, end=" ")
    print()


# Main.
T = 1
for i in range(T):
    root = takeInput()
    ans = getTopView(root)
    printAns(ans)
