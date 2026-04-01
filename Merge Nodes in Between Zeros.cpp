//https://leetcode.com/problems/merge-nodes-in-between-zeros/description/

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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp=head;
        int summ=0;
        ListNode* prev0=head;
        ListNode* prev=temp;
        while(temp!=NULL){
            if(temp->val==0 && summ!=0){
                prev0->val=summ;
                summ=0;
                prev0->next=temp;
                prev=prev0;
                prev0=temp;
            }
            else{
                summ+=temp->val;
            }
            temp=temp->next;
        }
        prev->next=NULL;
        return head;
    }
};
