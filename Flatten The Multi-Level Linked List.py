#
from os import *
from sys import *
from collections import *
from math import *

import queue
from sys import stdin


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.child = None


def flattenMultiLinkedList(head):

    # Write your function here.
    new=[]
    temp=head
    prev=None
    while temp!=None:
        if temp.child!=None:
            new.append(temp.child)
            temp.child=None
        prev=temp
        temp=temp.next
    while new:
        node=new.pop(0)
        prev.next=node
        #print(node.data)
        if node.child!=None:
            new.append(node.child)
            node.child=None
        if node!=None:
            temp=node
            while temp!=None:
                if temp.child!=None:
                    new.append(temp.child)
                    temp.child=None
                prev=temp
                temp=temp.next
    return head







def build_multilevel_linkedList(arr):

    if len(arr) == 0 or arr[0] == -1:
        return None

    head = Node(arr[0])
    q = queue.Queue()
    q.put(head)
    i = 0

    while q.empty() is False:
        curr = q.get()

        i += 1
        if arr[i] != -1:
            next_node = Node(arr[i])
            curr.next = next_node
            q.put(next_node)

        i += 1
        if arr[i] != -1:
            child_node = Node(arr[i])
            curr.child = child_node
            q.put(child_node)

    return head


# Main Code.
t = int(input().strip())

for i in range(t):
    arr = list(map(int, stdin.readline().strip().split(" ")))
    head = build_multilevel_linkedList(arr)

    res_head = flattenMultiLinkedList(head)

    while res_head is not None:
        print(res_head.data, end=" ")
        res_head = res_head.next

    print()
