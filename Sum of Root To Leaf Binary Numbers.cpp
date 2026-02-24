//https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/description/?envType=daily-question&envId=2026-02-24


class Solution {
public:
    int dfs(TreeNode* root, int current) {
        if (!root) return 0;

        current = current * 2 + root->val;

        if (!root->left && !root->right)
            return current;

        return dfs(root->left, current) + dfs(root->right, current);
    }

    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};
