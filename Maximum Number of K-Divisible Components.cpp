//https://leetcode.com/problems/maximum-number-of-k-divisible-components/description/?envType=daily-question&envId=2025-11-28


class Solution {
private:
    unordered_map<int,vector<int>> map;
    int result=0;
public:
    int helper(int node,int parent,vector<int>& values,int &k){
        int summ=values[node];
        for(int i:map[node]){
            if(i!=parent){  //as undirected... so shouldnt loop in infinite
                summ=summ+(helper(i,node,values,k))%k;
            }
        }
        if(summ%k==0) result++;
        return summ;

    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        for(auto e:edges){
            map[e[0]].push_back(e[1]);
            map[e[1]].push_back(e[0]);
        }
        int x=helper(0,-1,values,k);
        return result;
        
       
    }
};
