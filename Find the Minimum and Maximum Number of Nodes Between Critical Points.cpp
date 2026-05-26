//https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/


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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* temp=head;
        ListNode* prev=temp;
        vector<int> idx;
        int i=0;
        while(temp->next!=NULL){
            if(prev==temp) temp=temp->next;
            else{
                if((temp->val<prev->val && temp->val<temp->next->val) ||(temp->val>prev->val && temp->val>temp->next->val)) idx.push_back(i);
                prev=temp;
                temp=temp->next;
            }
            i++;
        }
        if(idx.size()<=1) return {-1,-1};
        int minD=INT_MAX;
        for(int j=0;j<idx.size()-1;j++){
            minD=min(minD,idx[j+1]-idx[j]);
        }
        int maxD=idx[idx.size()-1]-idx[0];
        return {minD, maxD};
    }
};
