//https://leetcode.com/problems/diameter-of-binary-tree/description/

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
    int diameter(TreeNode *&parent,int &maximum){
        //postorder
        if(parent==nullptr){
            return -1;  //beyond leaf
        }
        int left=1+diameter(parent->left,maximum); // leaf will be at 0..and its parent will get 1 for the leaf
        int right=1+diameter(parent->right,maximum);
        if(left+right>maximum){
            maximum=left+right; //store the maximum
        }
        return max(left,right);//return the maximum height till that node
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maximum=0;
        diameter(root,maximum);
        return maximum;

    }
};
