//https://www.hackerrank.com/contests/software-engineer-prep-kit/challenges/reverse-even-indexed-nodes/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep) {
    while (node) {
        cout << node->data;

        node = node->next;

        if (node) {
            cout << sep;
        }
    }
}



/*
 * Complete the 'extractAndAppendSponsoredNodes' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts INTEGER_SINGLY_LINKED_LIST head as parameter.
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* reverse(SinglyLinkedListNode* head){
    SinglyLinkedListNode* temp=head;
    SinglyLinkedListNode* prev=nullptr;
    SinglyLinkedListNode* nextt=head;
    while(temp!=nullptr){
        nextt=temp->next;
        temp->next=prev;
        prev=temp;
        temp=nextt;
    }
    return prev;
}
pair<SinglyLinkedListNode* ,SinglyLinkedListNode*>  seperator(SinglyLinkedListNode* head){
    int idx=0;
    SinglyLinkedListNode* h1=nullptr;
    SinglyLinkedListNode* t1=nullptr;
    SinglyLinkedListNode* h2=nullptr;
    SinglyLinkedListNode* t2=nullptr;
    SinglyLinkedListNode* temp=head;
    while(temp!=NULL){
        if(idx&1){
            if(h2==nullptr){
                h2=temp;
                temp=temp->next;
                h2->next=nullptr;
                t2=h2;
            }
            else{
                t2->next=temp;
                temp=temp->next;
                t2=t2->next;
                t2->next=nullptr;
            }
        }
        else{
            if(h1==nullptr){
                h1=temp;
                temp=temp->next;
                h1->next=nullptr;
                t1=h1;
            }
            else{
                t1->next=temp;
                temp=temp->next;
                t1=t1->next;
                t1->next=nullptr;
            }
        }
        idx++;
    }
    return {h1,h2};
    
}

SinglyLinkedListNode* extractAndAppendSponsoredNodes(SinglyLinkedListNode* head) {
    pair<SinglyLinkedListNode*, SinglyLinkedListNode*> p=seperator(head);
    p.first=reverse(p.first);
    if(p.second==nullptr) return p.first;
    
    SinglyLinkedListNode* temp=p.second;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=p.first;
    return p.second;
}

int main()
{
    SinglyLinkedList* head = new SinglyLinkedList();

    string head_count_temp;
    getline(cin, head_count_temp);

    int head_count = stoi(ltrim(rtrim(head_count_temp)));

    for (int i = 0; i < head_count; i++) {
        string head_item_temp;
        getline(cin, head_item_temp);

        int head_item = stoi(ltrim(rtrim(head_item_temp)));

        head->insert_node(head_item);
    }

    SinglyLinkedListNode* result = extractAndAppendSponsoredNodes(head->head);

    print_singly_linked_list(result, "\n");
    cout << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
