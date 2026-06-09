//https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/description/


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
class FindElements {
private:
    TreeNode* root;
public:
    FindElements(TreeNode* root) {
        if(root) {
            root->val=0;
            helper(root->left,0,1);
            helper(root->right,0,0);
        }
        this->root=root;
    }

    void helper(TreeNode* parent, int pVal, bool isLeft){
        if(parent==NULL) return;
        int val=pVal*2;
        if(isLeft) parent->val=val+1;
        else parent->val=val+2;

        helper(parent->left,parent->val,1);
        helper(parent->right,parent->val,0);
    }
    bool preOrder(int target, TreeNode* node){
        if(node==NULL) return false;

        if(node->val==target) return true;
        if(preOrder(target,node->left)) return true;
        if(preOrder(target,node->right)) return true;

        return false;
    }
    bool find(int target) {
        return preOrder(target,root);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
