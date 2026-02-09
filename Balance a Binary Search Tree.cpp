//https://leetcode.com/problems/balance-a-binary-search-tree/description/?envType=daily-question&envId=2026-02-09

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
    void inorder(TreeNode* p, vector<int> &arr){
        if(p == NULL) return;
        inorder(p->left, arr);
        arr.push_back(p->val);
        inorder(p->right, arr);
    }

    TreeNode* bbst(vector<int> listt){
        int l=listt.size();
        if(l==0) return NULL;
        int mid=l/2;
        TreeNode* node= new TreeNode();
        node->val=listt[mid];
        vector<int> left(listt.begin(),listt.begin()+mid);
        vector<int> right(listt.begin()+mid+1,listt.end());
        node->left=bbst(left);
        node->right=bbst(right);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorder(root,arr);
        root=NULL;
        int l=arr.size();
        int mid=l/2;
        TreeNode* node= new TreeNode();

        node->val=arr[mid];

        vector<int> left(arr.begin(),arr.begin()+mid);
        vector<int> right(arr.begin()+mid+1,arr.end());
        node->left=bbst(left);
        node->right=bbst(right);

        return node;
    }
};
