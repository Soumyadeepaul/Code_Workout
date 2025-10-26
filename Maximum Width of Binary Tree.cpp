//https://leetcode.com/problems/maximum-width-of-binary-tree/description/


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
    // Pass queues by reference to avoid copies
    void levelOrder(queue<pair<TreeNode*, unsigned long long>> &curr,
                    queue<pair<TreeNode*, unsigned long long>> &next,
                    unsigned long long &width) {
        
        if (curr.empty()) return;

        unsigned long long minn = ULLONG_MAX;
        unsigned long long maxx = 0;
        unsigned long long base = curr.front().second; // normalize indices per level

        while (!curr.empty()) {
            auto p = curr.front();
            curr.pop();

            unsigned long long idx = p.second - base;  // very important

            if (p.first->left) {
                next.push({p.first->left, idx * 2});
                minn = min(minn, idx * 2);
                maxx = max(maxx, idx * 2);
            }
            if (p.first->right) {
                next.push({p.first->right, idx * 2 + 1});
                minn = min(minn, idx * 2 + 1);
                maxx = max(maxx, idx * 2 + 1);
            }
        }

        if (!next.empty())
            width = max(width, maxx - minn + 1);
    }

    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, unsigned long long>> s1;
        queue<pair<TreeNode*, unsigned long long>> s2;
        s1.push({root, 0});

        unsigned long long width = 1;
        int turn = 0;

        while ((!s1.empty()) || (!s2.empty())) {
            if (turn == 0) {
                levelOrder(s1, s2, width);
                turn = 1;
            } else {
                levelOrder(s2, s1, width);
                turn = 0;
            }
        }

        return (int)width;
    }
};
