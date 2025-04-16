#https://www.naukri.com/code360/problems/interview-shuriken-42-detect-and-remove-loop_241049

from typing import *

# Following is the structure of  Node
# Do not update or change the structure 

class Node:

    def __init__(self, val):
        self.val = val
        self.next = None

def removeLoop(head :Node) -> Node :

    # Write your code
    slow=head
    fast=head
    while fast and fast.next:
        slow=slow.next
        fast=fast.next.next
        if fast==slow:
            break
    
    if fast==None:
        return head
    
    slow=head
    prev=fast
    while fast!=slow:
        slow=slow.next
        prev=fast
        fast=fast.next
    prev.next=None
    return head
