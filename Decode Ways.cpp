//https://leetcode.com/problems/decode-ways/


class Solution {
public:
    int wordBreakApproach(string s,vector<int>&dp,unordered_map<string,string> &map,int pos){
        if(pos==s.size()) {
            return 1;
        }
        if(dp[pos]!=-1) return dp[pos];


        int val=0;
        for(int i=pos;i<s.size();i++){
            string newS=s.substr(pos,i-pos+1);
            if(stoi(newS)>0 && stoi(newS)<27)
                val+=wordBreakApproach(s,dp,map,i+1);
            else
                break;
        }
        return dp[pos]=val;
    }
    int numDecodings(string s) {
        unordered_map<string,string> map;
        for(int i=1;i<=26;i++){
            map[to_string(i)]=i+64;
        }
        vector<int>dp(s.size(),-1);
        int count=0;
        count=wordBreakApproach(s,dp,map,0);
        return count;
    }
};
