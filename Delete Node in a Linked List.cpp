//https://leetcode.com/problems/delete-node-in-a-linked-list/description/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* previous;
        while(node->next!=nullptr){
            previous=node;
            node->val=node->next->val;
            node=node->next;
        }

        previous->next=nullptr;
    }
};
