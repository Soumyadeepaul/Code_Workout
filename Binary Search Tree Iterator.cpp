//https://leetcode.com/problems/binary-search-tree-iterator/description/?envType=problem-list-v2&envId=design


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
private:
    vector<int> store;
    void helper(TreeNode* node){
        if(node){
            if(node->left){helper(node->left);}
            store.push_back(node->val);
            if(node->right){helper(node->right);}
        }
    }
    int idx=0;
public:
    BSTIterator(TreeNode* root) {
        helper(root);
    }
    
    int next() {
        return store[idx++];
    }
    
    bool hasNext() {
        if(idx<store.size()) return true;
        return false;   
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
