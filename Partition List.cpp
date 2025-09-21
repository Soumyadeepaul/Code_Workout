//https://leetcode.com/problems/partition-list/description/


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
    ListNode* partition(ListNode* head, int x) {
        if(head==nullptr) return head;
        if(head->next==nullptr) return head;
        ListNode* last;
        ListNode* lastStop;
        ListNode* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        lastStop=temp;
        last=temp;//will join and traverse

        temp=head;
        ListNode*previous=nullptr;
        ListNode*nextt;
        while(temp!=lastStop){
            if(temp->val>=x){
                if(temp==head){
                    head=temp->next;
                    nextt=temp->next;
                    last->next=temp;
                    last=last->next;
                    temp->next=nullptr;
                    temp=head;
                    continue;
                }
                else{
                    nextt=temp->next;
                    previous->next=nextt;
                    last->next=temp;
                    temp->next=nullptr;
                    temp=nextt;
                    last=last->next;
                }
            }
            else{
                previous=temp;
                temp=temp->next;
            }
            
        }
        if(temp->val>=x){
            if(temp==head){
                head=temp->next;
            }
            else{
                if(temp->next!=nullptr){
                    previous->next=temp->next;
                }
                else{
                    previous->next=last;
                }
                
            }
            last->next=temp;
            temp->next=nullptr;
        }
        return head;

    }
};
