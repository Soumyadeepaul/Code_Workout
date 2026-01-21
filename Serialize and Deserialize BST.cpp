//https://leetcode.com/problems/serialize-and-deserialize-bst/?envType=problem-list-v2&envId=breadth-first-search


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string converterB(int i){
        string result="";
        int count=0;
        int s=i;
        while(s){
            if(s%2==1) result="1"+result;
            else result="0"+result;
            s=s/2;
            count++;
        }
        result=string(15-count,'0')+result;
        return result;
    }
    void helper(TreeNode* root, string &result){
        if(root){
            result+=converterB(root->val);
            helper(root->left,result);
            helper(root->right,result);
        }
    }
    string serialize(TreeNode* root) {
        string result="";
        helper(root,result);
        return result;
    }
    int helper2(string s){
        int l=s.size()-1;
        int result=0;
        int p=1;
        while(s.size()!=0){
            if(s[l]=='1') result+=p;
            p<<=1;
            s.pop_back();
            l--;
        }
        return result;
    }
    TreeNode* tree(vector<string> store){
        if(store.size()==0) return NULL;
        TreeNode* n=new TreeNode();
        int val=helper2(store[0]);
        n->val=val;
        vector<string> left;
        int i=1;
        for(;i<store.size();i++){
            if(store[i]<store[0]) left.push_back(store[i]);
            else break;
        }

        vector<string> right(store.begin()+i,store.end());
        n->left=tree(left);
        n->right=tree(right);
        return n;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root;
        vector<string> store;
        for(int i=0;i<data.size();i+=15){
            store.push_back(data.substr(i,15));
        }
        root=tree(store);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
