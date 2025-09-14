//https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/



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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr1=head;
        ListNode* curr2=NULL;

        while(curr1->next!=nullptr){
            curr2=curr1;
            curr1=curr1->next;
            ListNode* node=new ListNode();
            for(int i=min(curr2->val,curr1->val);i>0;i--){
                if(curr1->val%i==0 && curr2->val%i==0){
                    node->val=i;
                    break;
                }
            }
            node->next=curr1;
            curr2->next=node;
        }

        return head;
    }
};
