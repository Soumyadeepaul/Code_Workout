#https://www.naukri.com/code360/problems/divide-linked-list-in-two_763646


from os import *
from sys import *
from collections import *
from math import *

'''

    Following is the list node structure:
    
    class Node:
        def __init__(self, data):
            self.data = data
            self.next = None
'''
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def divideList(head):
    # Write your code here.
    temp1=None
    prev1=None
    temp1Head=None
    temp2=None
    temp2Head=None
    prev2=None
    
    even=0
    while head:
        if even==0:
            if temp1Head!=None:
                prev1=temp1
            temp1=Node(head.data)
            temp1.next=None
            if temp1Head!=None:
                prev1.next=temp1
            if temp1Head==None:
                temp1Head=temp1
            head=head.next
            even=1
        else:
            if temp2Head!=None:
                prev2=temp2
            temp2=Node(head.data)
            temp2.next=None
            if temp2Head!=None:
                prev2.next=temp2
            if temp2Head==None:
                temp2Head=temp2
            head=head.next
            even=0

            
    return [temp1Head,temp2Head]
