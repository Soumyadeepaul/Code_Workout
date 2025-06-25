#https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/?envType=study-plan-v2&envId=top-interview-150

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:         
        if not head:
            return None
        temp=head.next
        prevTemp=head
        duplicates=set()
        while temp:
            if temp.val==prevTemp.val:
                prevTemp.next=temp.next
                temp=None
                temp=prevTemp.next
                duplicates.add(prevTemp.val)
            else:
                prevTemp=temp
                temp=temp.next
                
        temp=head
        prevTemp=head
        while temp:
            if temp.val in duplicates:
                if temp!=head:
                    
                    prevTemp.next=temp.next
                    temp=None
                    temp=prevTemp.next
                    
                else:
                    head=temp.next
                    prevTemp=temp.next
                    temp=None
                    temp=head
            else:
                prevTemp=temp
                temp=temp.next
                

        return head
