//https://leetcode.com/problems/remove-nth-node-from-end-of-list/


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int l=0;
        while(temp!=nullptr){
            temp=temp->next;
            l++;
        }
        int target=l-n;
        temp=head;
        ListNode *prev=nullptr;
        if(target==0){
            head=temp->next;
            delete temp;
            return head;
        }
        while(target!=0){
            prev=temp;
            temp=temp->next;
            target--;
        }
        prev->next=temp->next;
        delete temp;
        return head;
    }
};
