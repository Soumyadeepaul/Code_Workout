from collections import *
from math import *

# Following is the Linked list node class
class Node:
    def __init__(self, x):
        self.data = x
        self.next = None

from typing import *

def modularNode(k: int, head: Node)-> Node:
    
    # Write your Code here
    nodeCount=1
    temp=head
    ans=0
    while temp:
        if nodeCount%k==0:
            ans=temp
        temp=temp.next
        nodeCount+=1
    return ans
