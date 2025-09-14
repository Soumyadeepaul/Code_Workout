//https://leetcode.com/problems/rotate-list/description/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr) return head;
        if(head->next==nullptr) return head;
        ListNode* slow=head;
        ListNode* fast=head;
        int count=1;
        while(fast->next!=nullptr && fast->next->next!= nullptr){
            fast=fast->next->next;
            slow=slow->next;
            count+=2;
            
        }
        if(fast->next!=nullptr){
            count++;
        }
        int travel=count-(k%count);

        ListNode* temp=head;
        if(travel==count) return head;
        while(travel!=1){
            temp=temp->next;
            travel--;
        }
        
        ListNode* node=temp->next;
        temp->next=NULL;
        temp=node;
        while(temp && temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=head;
        head=node;
        return head;
    }
};
