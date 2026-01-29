//https://leetcode.com/problems/minimum-cost-to-convert-string-i/description/?envType=daily-question&envId=2026-01-29



class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<int> unique(26,0);
        for(char c: original) unique[c-'a']=1;
        for(char c: changed) unique[c-'a']=1;

        vector<vector<int>> floyd(26,vector<int>(26,1e9));

        for(int i=0;i<26;i++){
            floyd[i][i]=0;
        }
        
        for(int i=0;i<original.size();i++){
            floyd[original[i]-'a'][changed[i]-'a']=min(floyd[original[i]-'a'][changed[i]-'a'],cost[i]); // this min is for when let a->b has 2 ways... wt =2,5.. so that time we must take the min
        }

        for(int n = 0; n < 26; n++){
            if(unique[n] == 0) continue;
            for(int i = 0; i < 26; i++){
                if(unique[i] == 0) continue;
                for(int j = 0; j < 26; j++){
                    if(unique[j] == 0) continue;
                    if(floyd[i][n] == 1e9 || floyd[n][j] == 1e9) continue;
                    floyd[i][j] = min(floyd[i][j], floyd[i][n] + floyd[n][j]);
                }
            }
        }

        long long result = 0;
        for(int i = 0; i < source.size(); i++){
            if(source[i] == target[i]) continue;
            if(floyd[source[i]-'a'][target[i]-'a'] == 1e9) return -1;
            result += floyd[source[i]-'a'][target[i]-'a'];
        }

        return result;

    }
};
