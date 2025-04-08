class Node:
    def __init__(self,data):
        self.data = data
        self.next = None


def insert(head, n, pos, val):
    # Write your code here.
    temp=head
    prev=None
    n=Node(val)
    if pos!=0:
        while pos!=0:
            prev=temp
            temp=temp.next
            pos-=1
        prev.next=n
        n.next=temp
    else:
        n.next=temp
        head=n
    return head
