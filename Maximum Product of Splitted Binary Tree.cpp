//https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/?envType=daily-question&envId=2026-01-07


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
    static const int MOD = 1e9 + 7;
    void traverse(TreeNode* node,int &summ){
        if(node){
            summ+=node->val;
            traverse(node->left,summ);
            traverse(node->right,summ);
        }
    }
    int maxProduct(TreeNode *node, int &total, long long int &result){
        if(node){
            int current=node->val;
            current+=maxProduct(node->left,total,result);
            current+=maxProduct(node->right,total,result);
            result=max(result,(total-current)* 1LL * current);
            return current;
        }
        return 0;
    }
    int maxProduct(TreeNode* root) {
        int summ=0;
        traverse(root,summ);
        long long int result=0;
        maxProduct(root,summ,result);
        return result%MOD;
    }
};
