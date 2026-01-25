//https://leetcode.com/problems/add-two-numbers-ii/?envType=problem-list-v2&envId=stack


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
    ListNode* reverse(ListNode* l){
        ListNode* prev = NULL;
        ListNode* curr = l;
        ListNode* nextt = NULL;
        while(curr!=NULL){
            nextt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextt;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverse(l1);
        l2=reverse(l2);
        ListNode* head=NULL;
        ListNode* prev=head;
        int carry=0;
        while(l1!=NULL && l2!=NULL){
            
            int i=l1->val+l2->val+carry;
            carry=i/10;
            i=i%10;
            ListNode* node= new ListNode(i);
            if(head==NULL) head=prev=node;
            else prev->next=node;
            prev=node;
            l1=l1->next;
            l2=l2->next;

        }
        while(l1!=NULL){
            int i=l1->val+carry;
            carry=i/10;
            i=i%10;
            ListNode* node= new ListNode(i);
            
            prev->next=node;
            prev=node;
            l1=l1->next;
        }
        while(l2!=NULL){
            int i=l2->val+carry;
            carry=i/10;
            i=i%10;
            ListNode* node= new ListNode(i);

            prev->next=node;
            prev=node;
            l2=l2->next;
        }
        if(carry==1){
            ListNode* node= new ListNode(carry);
            prev->next=node;
        }

        head=reverse(head);
        return head;
    }
};
