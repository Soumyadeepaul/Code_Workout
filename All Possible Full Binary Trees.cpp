//https://leetcode.com/problems/all-possible-full-binary-trees/description/?envType=problem-list-v2&envId=dynamic-programming


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
    vector<TreeNode*> combo(int n,unordered_map<int,vector<TreeNode*>> &map){
        if(n%2==0){ // only even node possible
            return {};
        }
        else if(n==1){
            TreeNode* node=new TreeNode(0);
            return {node};
        }
        else if(map.find(n)!=map.end()){
            return map[n];
        }
        vector<TreeNode*> formation;
        for(int i=1;i<n;i+=2){
            vector<TreeNode*> left=combo(i,map);
            vector<TreeNode*> right=combo(n-1-i,map);
            for(TreeNode* l:left){
                for(TreeNode* r:right){
                    TreeNode* root=new TreeNode(0); //means all r diff combination
                    root->left=l;
                    root->right=r;
                    formation.push_back(root);
                }
            }
        }
        map[n]=formation;
        return map[n];
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        unordered_map<int,vector<TreeNode*>> map;
        vector<TreeNode*> trees=combo(n,map);
        return trees;
    }
};
