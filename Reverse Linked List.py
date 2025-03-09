#https://www.naukri.com/code360/problems/reverse-the-singly-linked-list_799897


from math import *
from collections import *
from sys import *
from os import *

"""***************************************************************

    Following is the class structure of the LinkedListNode class:

    class Node:
        def __init__(self, data):
            self.data = data
            self.next = None


*****************************************************************"""


def reverseLinkedList(head):
    # Write your code here.

    temp=head
    prev=None
    prev_last=None
    while temp:
        prev=temp
        temp=temp.next
        prev.next=prev_last
        prev_last=prev
    head=prev
    return head
