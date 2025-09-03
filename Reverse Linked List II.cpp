//https://leetcode.com/problems/reverse-linked-list-ii/description/?envType=study-plan-v2&envId=top-interview-150


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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right || head==nullptr) return head;

        //reverse the ll
        ListNode* hold=nullptr; // holds previous value of left   to join start of reverse node that is the right node of initial stage
        ListNode* temp=head;
        ListNode* previous=nullptr;
        ListNode* nextt=nullptr;
        ListNode* endReverse;   // holds the end element of the reverse that is the left node of initial stage
        int index= 1; //count index
        while(temp!=nullptr){
            if(index==left){  //when left found
                hold=previous;  // hold the left-1 node
                //reverse
                endReverse=temp;  // hold the left node... to join with the node after reversing
                previous=nullptr;  //assign previous to null
                while(index!=right+1){   // untill right + 1 arrives.. reverse
                    nextt=temp->next;
                    temp->next=previous;
                    previous=temp;
                    temp=nextt;
                    index++;
                }
                endReverse->next=temp; // join reversed last element (left) to the next node... temp can be null when right+1 =null
                if(hold==nullptr){// if hold is null means left 1
                    head=previous;
                }
                else{
                    hold->next=previous;
                }
                break;
            }
            //looping
            nextt=temp->next;
            previous=temp;
            temp=nextt;
            index++;
        }
        return head;
    }
    
};
