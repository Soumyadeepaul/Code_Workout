//https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/?envType=daily-question&envId=2025-11-01


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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* temp=head;
        ListNode* nextt;
        ListNode* prev=nullptr;
        unordered_set<int> map(nums.begin(),nums.end());
        while(temp!=nullptr){
            nextt=temp->next;
            if(map.find(temp->val)!=map.end()){
                if(temp==head){
                    head=nextt;
                    //delete temp;
                    temp=head;
                }
                else{
                    prev->next=temp->next;
                    //delete temp;
                    temp=nextt;
                }
            }
            else{
                prev=temp;
                temp=nextt;
            }
        }
        return head;
    }
};
