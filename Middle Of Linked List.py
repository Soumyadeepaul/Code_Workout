#https://www.naukri.com/code360/problems/middle-of-linked-list_973250

from math import *
from collections import *
from sys import *
from os import *

'''

    class Node:
        def __init__(self, data):
            self.data = data
            self.next = None

'''

def findMiddle(head):
    # Write your code here
    # head denoted head of linked list
    slow=head
    fast=head
    while fast.next!=None and fast.next.next!=None:
        slow=slow.next
        fast=fast.next.next
    if fast.next!=None:
        slow=slow.next
    return slow
