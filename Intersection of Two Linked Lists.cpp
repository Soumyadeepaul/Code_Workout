//https://leetcode.com/problems/intersection-of-two-linked-lists/


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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> nodes;
        ListNode* temp=headA;
        while(temp!=nullptr){
            nodes.insert(temp);
            temp=temp->next;
        }
        temp=headB;
        while(temp!=nullptr){
            if(nodes.find(temp)!=nodes.end()){
                return temp;
            }
            temp=temp->next;
        }
        return nullptr;
    }
};
