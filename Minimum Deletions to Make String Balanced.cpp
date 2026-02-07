//https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/?envType=daily-question&envId=2026-02-07


"Convert the string into binary where a=1 and b=0"
"at any point interating from left, keep track of count of b and a"
"check if we no remove b at the idx, and remove all a's at its right... is it making longest balanced string"
"check if we dont remove a at the idx, is it making longest bs if all b from its left is removed"
class Solution {
public:
    int minimumDeletions(string s) {
        int i=0;
        int j=s.size()-1;
        int count=0;
        vector<int> dp(s.size(),0);
        for(;i<=j;i++){
            if(s[i]=='a') dp[i]=1;
        }
        i=0;
        int acc=accumulate(dp.begin(),dp.end(),0);
        int aCount=0;
        int bCount=0;
        for(;i<=j;i++){
            if(s[i]=='b'){
                // keep the b and check removing all 'a' from its right making string longest or not
                int cal=s.size()-(acc-aCount)-bCount;
                count=max(count,cal);
                bCount++;
            }
            else if(s[i]=='a'){
                aCount++;
                int cal=s.size()-(acc-aCount)-bCount;
                count=max(count,cal);
            }
        }
        return s.size()-count;
    }
};
