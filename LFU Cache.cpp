//21/25 TLE
//https://leetcode.com/problems/lfu-cache/submissions/1765048324/


class LFUCache {
public:
    struct Node{
        int key;
        int val;
        Node* left=NULL;
        Node* right=NULL;
    };
    unordered_map<int,Node*> map; //key,pointer
    unordered_map<int,int> freq; //
    Node* head=new Node();
    Node* tail= new Node();
    int capacity;
    LFUCache(int capacity) {
        this->capacity=capacity;
        head->right=tail;
        tail->left=head;
    }
    
    int get(int key) {
        if(map.find(key)==map.end()) return -1;
        else{
            freq[key]++;
            Node* node=map[key];
            //set in head
            node->right->left=node->left;
            node->left->right=node->right;
            node->left=head;
            node->right=head->right;
            head->right->left=node;
            head->right=node;
            return node->val;
        }
        
    }
    
    void put(int key, int value) {
        
        if (map.find(key)!=map.end()){ //found
            Node* node=map[key];
            node->val=value;
            freq[key]++;
            //send to connect to head;
            node->right->left=node->left;
            node->left->right=node->right;
            node->left=head;
            node->right=head->right;
            head->right->left=node;
            head->right=node;
        }
        else{//not found
            if(map.size()==capacity){// capcity will exceed now remove least freq
                int minimumF=INT_MAX;
                unordered_set<int> keyStore;
                for(auto &pair:freq){
                    if(pair.second<minimumF){
                        minimumF=pair.second;
                        keyStore.clear();
                        keyStore.insert(pair.first);
                    }
                    else if(pair.second==minimumF){
                        keyStore.insert(pair.first);
                    }
                }
                if(keyStore.size()>1){
                    //traverse from tail.. the one that comes first out
                    Node *temp=tail->left;

                    while (temp!=head){
                        if(keyStore.find(temp->key)!=keyStore.end()){
                            //delete it
                            temp->right->left=temp->left;
                            temp->left->right=temp->right;
                            map.erase(temp->key);
                            freq.erase(temp->key);
                            delete temp;
                            
                            break;
                        }
                        temp=temp->left;
                    }
                }
                else{
                    auto v=next(keyStore.begin(), 0);
                    Node* dNode=map[*v];
                    dNode->right->left=dNode->left;
                    dNode->left->right=dNode->right;
                    delete dNode;
                    map.erase(*v);
                    freq.erase(*v);
                }
                
            }
            Node* node=new Node();
            node->key=key;
            node->val=value;
            // put from head side
            node->right=head->right;
            head->right->left=node;
            node->left=head;
            head->right=node;
            map.insert({key,node});
            freq.insert({key,1});
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
