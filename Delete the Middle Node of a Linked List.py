#https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/?envType=study-plan-v2&envId=leetcode-75

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        temp=head
        count=0
        while temp!=None and count<5:
            count+=1
            temp=temp.next
        if count==1:
            return None
        if count<5:
            count=count//2
            prev=None
            temp=head
            while count!=0:
                prev=temp
                temp=temp.next
                count-=1
            prev.next=temp.next
            temp=None
            return head
        prev=None
        slow=head
        fast=head
        while fast.next!=None and fast.next.next!=None:
            prev=slow
            slow=slow.next
            fast=fast.next.next
        if fast.next!=None:
            prev=slow
            slow=slow.next
        prev.next=slow.next
        slow=None
        return head
        
