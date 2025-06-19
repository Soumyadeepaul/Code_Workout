#https://leetcode.com/problems/add-two-numbers/?envType=study-plan-v2&envId=top-interview-150

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        
        temp1=l1
        temp2=l2
        temp1Prev=None
        carry=0
        while temp1 and temp2:
            summ=temp1.val+temp2.val+carry
            carry=summ//10
            summ=summ%10
            temp1.val=summ
            temp1Prev=temp1
            temp1=temp1.next
            temp2=temp2.next

        while temp2:
            summ=carry+temp2.val
            carry=summ//10
            summ=summ%10
            temp2.val=summ
            temp1Prev.next=temp2
            temp1Prev=temp2
            temp2=temp2.next
        
        while temp1:
            summ=carry+temp1.val
            carry=summ//10
            summ=summ%10
            temp1.val=summ
            
            temp1Prev=temp1
            temp1=temp1.next
        
        if carry:
            node=ListNode(carry)
            temp1Prev.next=node
        return l1
