//https://leetcode.com/problems/merge-k-sorted-lists/description/


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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=NULL;
        int l=lists.size();
        ListNode *p;
        int minn;
        ListNode *previous=nullptr;
        int index;
        while (true){
            minn=INT_MAX;
            index=-1;
            for(int i=0;i<l;i++){
                if(lists[i]==NULL){

                }
                else if(lists[i]->val<minn){
                    minn=lists[i]->val;
                    p=lists[i];
                    index=i;
                }
            }
            if(index==-1) break;
            if(p->next==nullptr){
                ListNode *t=NULL;
                lists[index]=t;
            }
            lists[index]=p->next;
            if(head==NULL){
                head=p;
                p->next=nullptr;
                previous=p;
            }
            else{
                previous->next=p;
                p->next=nullptr;
                previous=p;
            }

        }
        return head;
    }
};
