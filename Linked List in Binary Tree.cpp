//https://leetcode.com/problems/linked-list-in-binary-tree/description/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    //tle
    bool preOrder(ListNode* temp, TreeNode* node){
        if(temp==NULL) return true;
        if(node==NULL) return false;
        if(node->val==temp->val){
            if(preOrder(temp->next,node->left)) return true;
            if(preOrder(temp->next,node->right)) return true;
        }
        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(preOrder(head,root)) return true;
        if(root==NULL) return false;
        return (isSubPath(head,root->left) || isSubPath(head,root->right));
    }
};
