//https://leetcode.com/problems/jump-game-vii/description/?envType=daily-question&envId=2026-05-25


class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int l=s.size()-1;
        if(s[l]=='1') return false;

        vector<int> reachableIdx={l};
        for(int i=l-1;i>-1;i--){
            if(s[i]=='1') continue;

            for(int j=reachableIdx.size()-1;j>-1;j--){
                if(reachableIdx[j]>=(i+minJump) && reachableIdx[j]<=min(l,(i+maxJump))){
                    reachableIdx.emplace_back(i);
                    break;
                }
            }
            
        }
        return reachableIdx[reachableIdx.size()-1]==0;
    }
};
