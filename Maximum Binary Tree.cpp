//https://leetcode.com/problems/maximum-binary-tree/description/?envType=problem-list-v2&envId=monotonic-stack


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
    int maxIdx(vector<int>& nums, int left, int right){
        int idx=left;
        int maxi=nums[left];
        for(int i=left;i<right;i++){
            if(maxi<nums[i]){
                maxi=nums[i];
                idx=i;
            }
        }
        return idx;
    }
    TreeNode* create(vector<int>& nums, int left, int right){
        if(left>=right) return NULL;
        int idx=maxIdx(nums,left,right);
        TreeNode* parent=new TreeNode(nums[idx]);
        parent->left=create(nums,left,idx);
        parent->right=create(nums,idx+1,right);
        return parent;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int right=nums.size();
        return create(nums,0,right);
    }
};
