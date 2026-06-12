//https://leetcode.com/problems/stone-game/description/


class Solution {
public:
    vector<vector<int>> dp; //for alice only
    int helper(vector<int>& piles, int i, int j, bool turnA){
        if(i>j) return 0;
        if(i==j){
            if(turnA){
                return dp[i][j]=piles[i];
            }
        }
        if(turnA){
            if(dp[i][j]!=-1) return dp[i][j];
        }
        int left=0, right=0;
        if(turnA){
            left=piles[i];
            right=piles[j];
        }
        return dp[i][j]=max(helper(piles,i+1,j,!turnA)+left,helper(piles,i,j-1,!turnA)+right);
    }
    bool stoneGame(vector<int>& piles) {
        dp.assign(piles.size(),vector<int>(piles.size(),-1));
        int alice=helper(piles,0,piles.size()-1,true);
        int total=accumulate(piles.begin(),piles.end(),0);
        return alice>total-alice;
    }
};
