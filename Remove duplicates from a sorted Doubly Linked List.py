#https://www.naukri.com/code360/problems/unique-sorted-list_2420283

class Node:
    def __init__(self, data=0, next=None, prev=None):
        self.data = data
        self.next = next
        self.prev = prev


# Don't change the code above.


def removeDuplicates(head: Node) -> Node:
    # Write your code here
    temp=head
    prev=None
    while temp.next!=None:
        prev=temp
        temp=temp.next
        if prev.data==temp.data:
            prev.next=temp.next
            temp.next=None
            temp=prev
    return head
