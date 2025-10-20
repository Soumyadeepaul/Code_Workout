//https://leetcode.com/problems/binary-tree-level-order-traversal-ii/


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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==nullptr) return {};
        queue<pair<TreeNode*,int>> bfs;
        int rootTaken=0;
        int rootNotTaken=0;
        bfs.push({root,0});
        vector<vector<int>> result;
        int prevLevel=0;
        vector<int> store;
        while(!bfs.empty()){
            auto [node,level]=bfs.front();
            bfs.pop();
            if(prevLevel==level){
                store.push_back(node->val);
            }
            else{
                result.push_back(store);
                store.clear();
                store.push_back(node->val);
                prevLevel=level;
            }
            if(node->left!=nullptr)
            bfs.push({node->left,level+1});
            if(node->right!=nullptr)
            bfs.push({node->right,level+1});
        }
        result.push_back(store);
        reverse(result.begin(),result.end());
        return result;
        
    }
};
