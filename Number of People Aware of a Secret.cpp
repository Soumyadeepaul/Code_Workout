// MEMORY LIMIT EXCEED
//https://leetcode.com/problems/number-of-people-aware-of-a-secret/description/?envType=daily-question&envId=2025-09-09


class Solution {
public:
    struct Node{
        int person;
        int day;
        Node* left=NULL;
        Node* right=NULL;
    };
    // create the tree for n levels
    void tree(Node* parent,int n, int delay,int forget,int &alreadyUsed){
        if(n==1) return;
        //cout<<parent->person<<endl;
        if(parent->day==forget) {
            return; //node cant exceed
        }
        if(parent->day<delay){
            Node* node=new Node();
            node->person=parent->person;
            node->day=parent->day+1;
            parent->left=node;
            tree(parent->left,n-1,delay,forget,alreadyUsed);
        }
        else{
            Node* node=new Node();
            node->person=parent->person;
            node->day=parent->day+1;
            parent->left=node;
            Node* nodeNew=new Node();
            alreadyUsed++;
            nodeNew->person=alreadyUsed;
            //cout<<parent->person<<" "<<alreadyUsed<<"x"<<endl;
            nodeNew->day=1;
            parent->right=nodeNew;
            
            tree(parent->left,n-1,delay,forget,alreadyUsed);
            tree(parent->right,n-1,delay,forget,alreadyUsed);
        }

    }
    void count(Node* parent,int n,int &result,int &forget){
        if(parent->left==NULL and parent->right==NULL){
            //cout<<parent->person<<" "<<parent->day<<" "<<n<<endl;
            if(n==1 && parent->day!=forget+1) result++;
            return;
        }
        if(parent->left!=NULL){
            count(parent->left,n-1,result,forget);
        }
        if(parent->right!=NULL){
            count(parent->right,n-1,result,forget);
        }
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        Node* root=new Node();
        root->person=1;
        root->day=1;
        int alreadyUsed=1;
        tree(root,n,delay,forget,alreadyUsed);
        //count Leaf at nth level
        int result=0;
        count(root,n,result,forget);
        return result;
    }


    /////////////////////////////////////////////////////
    
};
