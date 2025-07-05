#

#include <bits/stdc++.h> 
/************************************************************

    Following is the linkedList class structure:

    class Node {
    public:
        int data;
        Node *next;

        Node(int val) {
            this->data = val;
            next = NULL;
        }
        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
};

************************************************************/

void merge(Node* head1, Node* head2)
{
    //    Write your code here
    Node *temp1=head1;
    Node *temp2=head2;

    while (temp1 && temp2){
        Node *t=temp2->next;
        temp2->next=temp1->next;
        temp1->next=temp2;
        temp1=temp2->next;
        temp2=t;
    }
}
