//https://leetcode.com/problems/reverse-nodes-in-k-group/description/


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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count=0;// count to match with k
        ListNode* temp=head; // for traverse
        ListNode* temp1=head;//for hold the head to reverse
        ListNode* prevHold; //hold the head of every k
        ListNode* p;// hold the head(tail after reverse) of every k
        bool headOnce=true;//to change head
        bool once=true;//used to hold the prevHold
        while(temp!=nullptr){
            count++;
            temp=temp->next;
            if(count==k){
                //cout<<count;
                count=0;
                //reverse
                ListNode* prev=temp;
                ListNode *curr=temp1;
                ListNode *nextt=temp1;
                // cout<<temp->val<<" "<<temp1->val<<endl;
                while(curr!=temp){
                    nextt=curr->next;
                    if(once==true){
                        once=false;
                        prevHold=curr;// hold the head of every k before reverse
                    }
                    curr->next=prev;
                    prev=curr;
                    curr=nextt;
                }
                if(headOnce==true){
                    head=prev;//change head
                    temp1=curr;// set new temp1 head of next kth
                    headOnce=false;
                }
                else{
                    temp1=curr;
                    // cout<<p->val<<" "<<prev->val<<endl;
                    p->next=prev;//attach new head of kth with previous's tail
                }
                p=prevHold;//to hold the previous's tail
                once=true;
                
            }
        }
        return head;
    }
};
