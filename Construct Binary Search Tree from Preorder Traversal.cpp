//https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/


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
class Solution {
public:
    void tree(queue<int> &q,TreeNode* &parent,vector<int> left, vector<int> right){
        //if(q.empty()) return;
        if(!left.empty()){
            TreeNode* node=new TreeNode();
            node->val=q.front();
            parent->left=node;
            vector<int> left1;
            vector<int> right1;
            int i=0;
            for(;i<left.size();i++){
                if(left[i]<q.front()){
                    left1.push_back(left[i]);
                }
                else if(left[i]>q.front()){
                    right1.push_back(left[i]);
                }
            }
            q.pop();
            tree(q,parent->left,left1,right1);
        }
        if(!right.empty()){
            TreeNode* node=new TreeNode();
            node->val=q.front();
            parent->right=node;
            vector<int> left1;
            vector<int> right1;
            int i=0;
            for(;i<right.size();i++){
                if(right[i]<q.front()){
                    left1.push_back(right[i]);
                }
                else if(right[i]>q.front()){
                    right1.push_back(right[i]);
                }
            }
            q.pop();
            tree(q,parent->right,left1,right1);
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        queue<int> q;
        for(int i:preorder){
            q.push(i);
        }

        TreeNode* root=new TreeNode();
        root->val=q.front();
        
        vector<int> left;
        vector<int> right;
        int i=0;
        for(;i<q.size();i++){
            if(preorder[i]<q.front()){
                left.push_back(preorder[i]);
            }
            else if(preorder[i]>q.front()){
                right.push_back(preorder[i]);
            }
        }
        q.pop();
        tree(q,root,left,right);
        return root;
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////
// insert in bst

    void searchInsert(int i,TreeNode* &parent){
        if(parent->val==0){
            parent->val=i;
            return;
        }
        if(i<parent->val){
            if(parent->left!=nullptr){
                searchInsert(i,parent->left);
            }
            else{
                TreeNode* node=new TreeNode();
                node->val=i;
                parent->left=node;
                return;
            }
        }
        else if(i>parent->val){
            if(parent->right!=nullptr){
                searchInsert(i,parent->right);
            }
            else{
                TreeNode* node=new TreeNode();
                node->val=i;
                parent->right=node;
                return;
            }
        }
    }



    TreeNode* bstFromPreorder(vector<int>& preorder){
        TreeNode* root=new TreeNode();
        for(int i:preorder){
            searchInsert(i,root);
        }
        return root;
    }
