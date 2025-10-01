//https://leetcode.com/problems/lexicographical-numbers/description/

class Solution {
public:
    void make(int &n,vector<int> &result, int &store){
        for(int i=0;i<=9;i++){
            store=store*10+i;
            if(store<=n){
                result.push_back(store);
                make(n,result,store);
            }
            store/=10;
        }
    }
    vector<int> lexicalOrder(int n) {
        int store=0;
        vector<int> result;
        for(int i=1;i<=9;i++){
            store=store*10+i;
            if(store<=n){
                result.push_back(store);
                make(n,result,store);
            }
            store/=10;
        }
        return result;
    }
};
