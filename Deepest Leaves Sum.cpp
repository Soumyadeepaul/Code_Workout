//https://leetcode.com/problems/deepest-leaves-sum/description/


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
    int deepestLeavesSum(TreeNode* root) {
        //level order;
        int result=0;
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,0));
        int previousLevel=-1;
        while(!q.empty()){

            pair<TreeNode*,int>node=q.front();
            q.pop();
            if(node.second!=previousLevel){
                previousLevel=node.second;
                result=node.first->val;
            }
            else{
                result+=node.first->val;
            }
            if(node.first->left!=nullptr){
                q.push(make_pair(node.first->left,node.second+1));
            }
            if(node.first->right!=nullptr){
                q.push(make_pair(node.first->right,node.second+1));
            }
            
        }
        return result;
    }
};
