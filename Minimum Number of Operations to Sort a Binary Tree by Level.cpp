//https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/description/



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
    int minimumOperations(TreeNode* root) {
        if(root==nullptr) return {};
        queue<pair<TreeNode*,int>> bfs;
        int rootTaken=0;
        int rootNotTaken=0;
        bfs.push({root,0});
        int count=0;
        int prevLevel=0;
        vector<int> store;
        while(!bfs.empty()){
            auto [node,level]=bfs.front();
            bfs.pop();
            if(prevLevel==level){
                store.push_back(node->val);
            }
            else{
                // calculate
                //seletion sort
                int minn;
                for(int i=0;i<store.size();i++){
                    minn=i;
                    for(int j=i+1;j<store.size();j++){
                        if(store[minn]>store[j]){
                            minn=j;
                        }
                    }
                    if(minn!=i){
                        swap(store[minn],store[i]);
                        count++;
                    }
                }

                store.clear();
                store.push_back(node->val);
                prevLevel=level;
            }
            if(node->left!=nullptr)
            bfs.push({node->left,level+1});
            if(node->right!=nullptr)
            bfs.push({node->right,level+1});
        }
        int minn;
        for(int i=0;i<store.size();i++){
            minn=i;
            for(int j=i+1;j<store.size();j++){
                if(store[minn]>store[j]){
                    minn=j;
                }
            }
            if(minn!=i){
                swap(store[minn],store[i]);
                count++;
            }
        }
        
        return count;
    }
};
