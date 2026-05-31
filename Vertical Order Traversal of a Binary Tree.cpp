//Vertical Order Traversal of a Binary Tree



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
    vector<vector<int>> result;
    map<int,priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>> store;
    void helper(TreeNode * p, int level, int idx){
        if(p==NULL) return;
        store[idx].push({level,p->val});
        helper(p->left,level+1,idx-1);
        helper(p->right,level+1,idx+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        helper(root,0,0);
        for(auto p:store){
            vector<int> r;
            while(!p.second.empty()){
                r.push_back(p.second.top().second);
                p.second.pop();
            }
            result.push_back(r);
        }
        return result;
    }
};
