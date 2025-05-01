#https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/?envType=study-plan-v2&envId=leetcode-75

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        # fast=head
        # count=1
        # while fast.next and fast.next.next:
        #     fast=fast.next.next
        #     count+=2
        # if fast.next:
        #     count+=1
        # traverse=count//2
        # maxi=0
        # temp=head
        # i=0
        # find=count
        # while traverse!=0:
        #     val=temp.val
        #     node=temp
        #     x=i
        #     while x<find-1 and node.next and node.next.next:
        #         if x+2<find-1:
        #             node=node.next.next
        #         x+=2
        #     if x!=find-1:
        #         node=node.next
        #     find=find-1
        #     #print(val,node.val)
        #     maxi=max(maxi,val+node.val)
        #     temp=temp.next
        #     i+=1
        #     traverse-=1
        # return maxi
        ##############################################

        newHead=None
        slow=head
        fast=head
        while fast.next and fast.next.next:
            slow=slow.next
            fast=fast.next.next
        newHead=slow.next
        slow.next=None
        ##############
        #REVERSE second half
        temp=newHead
        prev=None
        while temp!=None:
            nextt=temp.next
            temp.next=prev
            prev=temp
            temp=nextt
        newHead=prev
        ###############
        temp=newHead
        maxi=0
        while head!=None:
            maxi=max(maxi,head.val+temp.val)
            head=head.next
            temp=temp.next
        return maxi
