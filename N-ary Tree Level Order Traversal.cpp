//https://leetcode.com/problems/n-ary-tree-level-order-traversal/description/


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {

        if(root==nullptr) return {};
        queue<pair<Node*,int>> bfs;
        int rootTaken=0;
        int rootNotTaken=0;
        bfs.push({root,0});
        vector<vector<int>> result;
        int prevLevel=0;
        vector<int> store;
        while(!bfs.empty()){
            auto [node,level]=bfs.front();
            bfs.pop();
            if(prevLevel==level){
                store.push_back(node->val);
            }
            else{
                result.push_back(store);
                store.clear();
                store.push_back(node->val);
                prevLevel=level;
            }
            for(Node* n:node->children){
                if(n!=nullptr)
                bfs.push({n,level+1});
            }
            
        }
        result.push_back(store);
        return result;
    }
};
