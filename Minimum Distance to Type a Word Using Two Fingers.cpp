//https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/description/?envType=daily-question&envId=2026-04-12


//TLE

class Solution {
public:
    int dis(int x1,int y1,int x2,int y2){
        return abs(x1-x2)+abs(y1-y2);
    }
    int result=1e9+7;
    
    void helper(string &w, int idx, int count, vector<vector<int>> &dp, char hand1, char hand2){
        if(idx==w.size()){
            result=min(result,count);
            return;
        }
        if(count>=result) return;
        //use hand2
        if(hand2=='\0') helper(w,idx+1,count,dp,hand1,w[idx]);
        else helper(w,idx+1,count+dp[hand2-'A'][w[idx]-'A'],dp, hand1, w[idx]);
        //dont use hand2
        helper(w,idx+1,count+dp[hand1-'A'][w[idx]-'A'], dp,w[idx], hand2);
    }
    int minimumDistance(string word) {
        unordered_map<char,vector<int>> store;
        char c='A';
        for(int i=0;i<5;i++){
            for(int j=0;j<6;j++){
                store[c++]={i,j};
            }
        }
        vector<vector<int>> dp(26,vector<int>(26,0));
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                dp[i][j]=dis(store['A'+i][0],store['A'+i][1],store['A'+j][0],store['A'+j][1]);
            }
        }
        
        helper(word,0,0,dp,word[0],'\0');
        return result;
    }
};
