#https://www.naukri.com/code360/problems/merge-two-sorted-linked-lists_800332

'''
    Following is the linked list node structure:
    class Node:
        def __init__(self, data):
        self.data = data
        self.next = None
'''
def sortTwoLists(first, second):
    
    head=None
    temp=None
    while first!=None and second!=None:
        if first.data<=second.data:
            if head==None:
                head=first
                temp=head
            else:
                temp.next=first
                temp=temp.next
            first=first.next
        else:
            if head==None:
                head=second
                temp=head
            else:
                temp.next=second
                temp=temp.next
            second=second.next
    if first!=None:
        temp.next=first
    if second!=None:
        temp.next=second
    return head
