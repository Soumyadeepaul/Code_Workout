//https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/?envType=daily-question&envId=2026-01-09


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


 // bfs + map child:parent
 // from last level node move up until found single node
class Solution {
public:

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        unordered_map<TreeNode*,TreeNode*> map; //child->parent
        queue<TreeNode*> bucket;
        bucket.push(root);
        vector<vector<TreeNode*>> store;
        store.push_back({root});
        vector<TreeNode*> hold;
        while(!bucket.empty()){
            TreeNode* p=bucket.front();
            bucket.pop();
            if(p->left!=NULL){
                hold.push_back(p->left);
                map[p->left]=p;
            }
            if(p->right!=NULL){
                hold.push_back(p->right);
                map[p->right]=p;
            }
            
            if(bucket.empty()){
                if(hold.size())
                store.push_back(hold);
                for(TreeNode* n:hold){
                    bucket.push(n);
                }
                hold.clear();
            }
        }
        vector<TreeNode*> leaf=store[store.size()-1];
        if(leaf.size()==1) return leaf[0];
        queue<TreeNode*> q(leaf.begin(),leaf.end());
        set<TreeNode*> parents;
        while(!q.empty()){
            TreeNode* p=q.front();
            q.pop();
            TreeNode *child=p;
            TreeNode *parent=map[p];
            if(map.count(child))
                parents.insert(parent);
            if(q.empty()){
                if(parents.size()==1){
                    for(TreeNode* i:parents) return i;
                }
                else{
                    for(TreeNode* i:parents){
                        q.push(i);
                    }
                }
                parents.clear();
            }
            
        }
        return root;
    }
};
