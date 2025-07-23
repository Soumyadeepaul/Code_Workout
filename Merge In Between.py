#


'''
    Following is the class structure of the Node class:

    class LinkedListNode:
    def __init__(self, data):
        self.data = data
        self.next = None
'''


def mergeInBetween(x: int, y: int, head1, head2):
    # write your code here
    temp=head1
    prevTemp=None
    idx=0
    while temp:
        if idx!=x:
            prevTemp=temp
            temp=temp.next
            idx+=1
        else:
            prevTemp.next=head2
            while idx!=y+1:
                temp=temp.next
                idx+=1
            temp2=head2
            while temp2.next!=None:
                temp2=temp2.next
            temp2.next=temp
            break
    return head1


