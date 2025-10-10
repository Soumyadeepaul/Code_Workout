//https://leetcode.com/problems/copy-list-with-random-pointer/description/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        Node* newHead=nullptr;
        Node* temp2;
        unordered_map<Node* ,Node*> map;
        while(temp!=nullptr){
            Node* node=new Node(temp->val);
            if(newHead==nullptr){newHead=node;
            temp2=newHead;}
            else{
                temp2->next=node;
                temp2=node;}
            map[temp]=temp2;
            temp=temp->next;
        }
        temp2=newHead;
        temp=head;
        while(temp!=nullptr){
            if(map.count(temp->random))
            temp2->random=map[temp->random];
            temp=temp->next;
            temp2=temp2->next;
        }
        return newHead;
    }
};
