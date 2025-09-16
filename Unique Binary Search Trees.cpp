//https://leetcode.com/problems/unique-binary-search-trees/


class Solution {
public:
    long long factorial(int i,int j){
        long long res=1;
        for(int x=0;x<j;x++){
            res*=(i-x);
            res/=(x+1);
        }
        return res;
    }
    int numTrees(int n) {
        return factorial(2*n,n)/(n+1);
    }
};
