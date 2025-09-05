//https://leetcode.com/problems/lru-cache/?envType=study-plan-v2&envId=top-interview-150


class LRUCache {
public:
    struct Dll{
        int key;
        int val;
        Dll* left=NULL;
        Dll* right=NULL;
    };
    Dll* head=new Dll();  //recently used will be closed to head
    Dll* tail=new Dll();  //least recently used will be close to tail
    
    int capacity;
    unordered_map<int,Dll*> cache;
    LRUCache(int capacity) {
        this->capacity=capacity;
        head->right=tail;
        tail->left=head;

    }
    
    int get(int key) {
        if(cache.find(key)==cache.end()){
            return -1;
        }
        Dll* nodePoint=cache[key];
        nodePoint->left->right=nodePoint->right;
        nodePoint->right->left=nodePoint->left;
        nodePoint->left=head;
        nodePoint->right=head->right;
        head->right->left=nodePoint; // which head was connected to
        head->right=nodePoint;
        return nodePoint->val;
        
    }
    
    void put(int key, int value) {
        if(cache.find(key)==cache.end()){ // not found;
            // check for the limit in cache
            if(cache.size()==capacity){
                //remove from tail
                Dll* deleteNode=tail->left;
                deleteNode->left->right=tail;
                deleteNode->right->left=deleteNode->left;
                cache.erase(deleteNode->key);
                delete deleteNode;
            }


            Dll* node=new Dll();
            node->key=key;
            node->val=value;
            node->left=head;
            node->right=head->right;
            head->right->left=node; // which head was connected to
            head->right=node;
            cache.insert({key,node});
        }
        else{
            Dll* nodePoint=cache[key];
            //1st join its left node to right and right to left
            nodePoint->left->right=nodePoint->right;
            nodePoint->right->left=nodePoint->left;
            nodePoint->left=head;
            nodePoint->right=head->right;
            head->right->left=nodePoint; // which head was connected to
            head->right=nodePoint;
            nodePoint->val=value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
