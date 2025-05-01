#https://leetcode.com/problems/odd-even-linked-list/?envType=study-plan-v2&envId=leetcode-75

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head==None:
            return head
        if head.next==None:
            return head
        curr=head
        prev=None
        nextt=head.next
        counter=1
        evenHead=head.next
        eventemp=evenHead
        oddHead=head
        while curr!=None:
            if counter&1:
                prev=curr
                curr=nextt
                if nextt!=None:
                    nextt=nextt.next
                counter=0
            else:
                eventemp.next=curr
                eventemp=eventemp.next
                prev.next=nextt
                curr.next=None
                curr=nextt
                if nextt!=None:
                    nextt=nextt.next
                counter=1
        prev.next=evenHead
        return head
