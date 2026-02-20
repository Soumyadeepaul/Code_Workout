//https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/


/*
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
    TreeNode* dC(vector<int> arr){
        int l=arr.size();
        if(l==0) return  NULL;
        int mid=l/2;

        vector<int> left(arr.begin(),arr.begin()+mid);
        vector<int> right(arr.begin()+mid+1,arr.end());
        TreeNode* node=new TreeNode(arr[mid]);
        node->left=dC(left);
        node->right=dC(right);
        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> lis;
        while(head!=NULL){
            lis.push_back(head->val);
            head=head->next;
        }
        return dC(lis);
    }
};
