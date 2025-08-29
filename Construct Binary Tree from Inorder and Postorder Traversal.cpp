//https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/?envType=study-plan-v2&envId=top-interview-150

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
    void algo(vector<int> left,vector<int> right, TreeNode *&parent,stack<int> &postOrder){
        //towards Right
        if(right.size()!=0){
            vector<int> left1;
            vector<int> right1;
            int data=postOrder.top();
            postOrder.pop();
            TreeNode *node=new TreeNode();
            node->val=data;
            parent->right=node;
            int i=0;
            for(;i<right.size();i++){
                if(right[i]!=data){
                    left1.push_back(right[i]);
                }
                else{
                    break;
                }
            }
            i++;
            for(;i<right.size();i++){
                right1.push_back(right[i]);
            }
            algo(left1,right1,node,postOrder);

        }

        //towards left
        if(left.size()!=0){
            vector<int> left1;
            vector<int> right1;
            int data=postOrder.top();
            postOrder.pop();
            TreeNode *node=new TreeNode();
            node->val=data;
            parent->left=node;
            int i=0;
            for(;i<left.size();i++){
                if(left[i]!=data){
                    left1.push_back(left[i]);
                }
                else{
                    break;
                }
            }
            i++;
            for(;i<left.size();i++){
                right1.push_back(left[i]);
            }
            algo(left1,right1,node,postOrder);

        }
        return;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        stack<int> postOrder;
        for(int i:postorder){
            postOrder.push(i);
        }
        vector<int> left;
        vector<int> right;
        int data=postOrder.top();
        postOrder.pop();
        TreeNode *root=new TreeNode();
        root->val=data;
        int i=0;
        for(;i<inorder.size();i++){
            if(inorder[i]!=data){
                left.push_back(inorder[i]);
            }
            else{
                break;
            }
        }
        i++;
        for(;i<inorder.size();i++){
            right.push_back(inorder[i]);
        }
        algo(left,right,root,postOrder);
        return root;
    }
};
