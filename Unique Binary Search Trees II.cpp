//https://leetcode.com/problems/unique-binary-search-trees-ii/description/



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
    vector<TreeNode*> helper(int left, int right){
        if(left==right) return {new TreeNode(left)};
        if(left > right) return {NULL};
        vector<TreeNode*> nodes;
        for(int i=left;i<=right;i++){
            for (auto left:helper(left,i-1)){
                for(auto right:helper(i+1,right)){
                    TreeNode* node=new TreeNode(i,left,right);
                    nodes.push_back(node);
                }
            }
        }
        return nodes;
    }
    vector<TreeNode*> generateTrees(int n) {
        return helper(1,n);
    }
};
