//https://leetcode.com/problems/add-one-row-to-tree/description/


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
    void bfs(TreeNode* &p,int &val, int &depth){
        queue<TreeNode*> q;
        queue<TreeNode*> store;
        q.push(p);
        int d=1;
        while(d!=depth-1){
            while(!q.empty()){
                TreeNode* hold=q.front();
                q.pop();
                if(hold->left!=NULL) store.push(hold->left);
                if(hold->right!=NULL) store.push(hold->right);
            }
            d++;
            while(!store.empty()){
                q.push(store.front());
                store.pop();
            }
        }
        while(!q.empty()){
            TreeNode* left=new TreeNode(val);
            TreeNode* right=new TreeNode(val);
            TreeNode* hold=q.front();
            q.pop();
            if(hold->left!=NULL){
                left->left=hold->left;
            }
            if(hold->right!=NULL){
                right->right=hold->right;
            }
            hold->left=left;
            hold->right=right;
        }

    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* node=new TreeNode();
            node->val=val;
            node->left=root;
            return node;
        }
        bfs(root,val,depth);
        return root;
    }
};
