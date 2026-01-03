//https://leetcode.com/problems/balanced-binary-tree/description/

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
    int check(TreeNode* p, bool &result){
        
        if(p->left==NULL && p->right==NULL){
            return 0;
        }
        int l=0;
        if(result==false) return false;
        if(p->left!=NULL){
            l=1+check(p->left,result);
        }
        int r=0;
        if(p->right!=NULL){
            r=1+check(p->right,result);
        }
        if(result==false) return false;
        int cal=abs(l-r);
        if(cal==0 || cal==1){
            result=true;
        }
        else{
            result=false;
        }
        return max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        bool result=true;
        int h=check(root,result);
        return result;
    }
};
