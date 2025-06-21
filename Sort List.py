#https://leetcode.com/problems/sort-list/description/?envType=study-plan-v2&envId=top-interview-150

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        temp=head
        listed=[]

        while temp:
            listed.append(temp.val)
            temp=temp.next
        
        listed.sort()

        temp=head
        i=0
        while temp:
            temp.val=listed[i]
            i+=1
            temp=temp.next
        
        return head
        
