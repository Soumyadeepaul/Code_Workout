#https://www.naukri.com/code360/problem-of-the-day/easy

from os import *
from sys import *
from collections import *
from math import *

'''
    Following is the class structure of the Node class:
    
    class Node:
        def __init__(self,data):
            self.data = data
            self.next = None
            self.prev = None
'''
class Node:
    def __init__(self,data):
        self.data = data
        self.next = None
        self.prev = None

def insert(k, val, head):
    # Write your code here.
    temp= head
    place=k
    prev=None
    while k:
        prev=temp
        temp=temp.next
        k-=1
    if place==0:
        node=Node(val)
        node.next=temp
        node.prev=temp.prev
        temp.prev=node
        head=node
    else:
        node=Node(val)
        node.next=prev.next
        node.prev=prev
        prev.next=node


    return head

