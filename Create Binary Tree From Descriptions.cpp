//https://leetcode.com/problems/create-binary-tree-from-descriptions/description/?envType=daily-question&envId=2026-06-07&roomId=knmqNg


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, TreeNode*> map;
    unordered_set<int> parents;
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

        for (int i = 0; i < descriptions.size(); i++) {
            TreeNode* parent;
            TreeNode* child;
            if (map.count(descriptions[i][0]))
                parent = map[descriptions[i][0]];
            else {
                TreeNode* node = new TreeNode(descriptions[i][0]);
                map[descriptions[i][0]] = node;
                parent = node;
            }
            if (map.count(descriptions[i][1]))
                child = map[descriptions[i][1]];
            else {
                TreeNode* node = new TreeNode(descriptions[i][1]);
                map[descriptions[i][1]] = node;
                child = node;
            }
            if (parents.find(child->val) != parents.end())
                parents.erase(child->val);
            parents.insert(parent->val);
            if (descriptions[i][2] == 0) {
                parent->right = child;
            } else
                parent->left = child;
        }
        if (parents.size() > 1) {
            for (int i = 0; i < descriptions.size(); i++) {
                TreeNode* parent;
                TreeNode* child;
                parent = map[descriptions[i][0]];
                child = map[descriptions[i][1]];
                if (parents.find(child->val) != parents.end())
                    parents.erase(child->val);
                if (descriptions[i][2] == 0) {
                    parent->right = child;
                } else
                    parent->left = child;
            }
        }
        int root;
        for (auto i = parents.begin(); i != parents.end(); i++) {
            root = *i;
        }
        return map[root];
    }
};
