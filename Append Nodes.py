#https://www.naukri.com/code360/problem-of-the-day/moderate

from os import *
from sys import *
from collections import *
from math import *

# Following is the class structure of the Node class:   
class Node:
    def __init__(self, data):
       	self.data = data
        self.next = None

def addNodes(head, n, m):
    # Write your code here.
    temp=head
    skip=m
    add=n
    summation=0
    lastNode=temp
    while temp:
        if skip!=0:
            skip-=1
            lastNode=temp
            temp=temp.next
            add=n
        else:
            if add==1:
                summation+=temp.data
                lastNode=temp
                add-=1
            elif add!=0:
                summation+=temp.data
                lastNode=temp
                temp=temp.next
                add-=1

            else:
                skip=m
                #adding the node
                new_node=Node(summation)
                #new_node.data=summation
                summation=0
                lastNode=temp
                new_node.next=temp.next
                temp.next=new_node
                temp=new_node.next
    if summation!=0:
        new_node=Node(summation)
        #new_node.data=summation
        summation=0
        new_node.next=lastNode.next
        lastNode.next=new_node
        lastNode=new_node.next
            
    return head

