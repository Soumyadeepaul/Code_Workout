//https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:

    Node* connect(Node* root) {
        if (root==NULL){
            return root;
        }
        queue<Node* > store;
        queue<int> level;
        store.push(root);
        level.push(0);
        Node* front;
        int previousLevel=-1;
        Node *previousNode=NULL;
        int l;
        while(!store.empty()){
            // cout<<store[0]->val;
            front=store.front();
            l=level.front();
            if(l!=previousLevel){
                previousNode=NULL;
                previousLevel=l;
            }
            if(previousNode!=NULL){
                front->next=previousNode;
            }
            previousNode=front;

            store.pop();
            level.pop();

            if(front->right!=NULL){
                store.push(front->right);
            }
            if(front->left!=NULL){
                store.push(front->left);
            }
            
            level.push(l+1);
            level.push(l+1);
        }
        return root;
    }
};
