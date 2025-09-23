//https://leetcode.com/problems/merge-in-between-linked-lists/description/


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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp=list1;
        int x=0;
        ListNode *hold;
        ListNode* temp2=list2;
        while(x!=a-1){
            temp=temp->next;
            x++;
            
        }
        hold=temp;
        while(x!=b){
            temp=temp->next;
            x++;
        }
        ListNode* remove=hold->next;
        ListNode* nextt;
        hold->next=list2;
        while(list2->next!=nullptr){
            list2=list2->next;
        }
        list2->next=temp->next;

        // while(remove->next!=nullptr){
        //     nextt=remove->next;
        //     delete remove;
        //     remove=nextt;
        // }
        return list1;
    }
};
