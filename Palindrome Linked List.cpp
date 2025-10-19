//https://leetcode.com/problems/palindrome-linked-list/description/


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
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* temp=slow->next;
        slow->next=nullptr;

        //reverse
        ListNode* prev=nullptr;
        ListNode* t1=temp;
        ListNode* nextt=t1;
        while(t1!=nullptr){
            nextt=t1->next;
            t1->next=prev;
            prev=t1;
            t1=nextt;
        }
        temp=prev;
        //check

        while(head!=nullptr && temp!=nullptr){
            if(head->val!=temp->val){
                return false;
            }
            head=head->next;
            temp=temp->next;
        }
        return true;
    }
};
