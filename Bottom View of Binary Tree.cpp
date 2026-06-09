//https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1


/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    unordered_map<int,pair<int,int>> map; //idx : level,data
    int mini=INT_MAX, maxi=INT_MIN;
    void helper(Node *parent, int idx, int level){
        if(parent==NULL) return;
        mini=min(mini,idx);
        maxi=max(maxi,idx);
        if(map.count(idx)) {
            if(map[idx].first<=level) map[idx]={level,parent->data};
        }
        else map[idx]={level,parent->data};
        helper(parent->left,idx-1,level+1);
        helper(parent->right,idx+1, level+1);
    }
    vector<int> bottomView(Node *root) {
        // code here
        helper(root,0, 0);
        vector<int> result;
        for(int i=mini;i<=maxi;i++){
            result.push_back(map[i].second);
        }
        return result;
        
    }
};
