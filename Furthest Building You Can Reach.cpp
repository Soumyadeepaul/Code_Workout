//https://leetcode.com/problems/furthest-building-you-can-reach/


class Solution {
public:
//     int helper(vector<int>& heights, int bricks, int ladders,int idx, int &maxIdx,        unordered_map<int,unordered_map<int,unordered_map<int,int>>> &dp
// ){
//         if(idx+1==heights.size()){
//             maxIdx=max(maxIdx,idx);
//             dp[idx][bricks][ladders]=maxIdx;
//             return maxIdx;
//         }
//         if(dp.count(idx) && dp[idx].count(bricks) && dp[idx][bricks].count(ladders)) return dp[idx][bricks][ladders];
//         if(heights[idx]>=heights[idx+1]) {
//             maxIdx=max(maxIdx,idx+1);
//             maxIdx=max(maxIdx,helper(heights,bricks,ladders,idx+1,maxIdx,dp));
//         }
//         else{
//             if(bricks-(heights[idx+1]-heights[idx])>=0){
//                 maxIdx=max(maxIdx,idx+1);
//                 dp[idx][bricks-(heights[idx+1]-heights[idx])][ladders]=maxIdx;
//                 maxIdx=max(maxIdx,helper(heights,bricks-(heights[idx+1]-heights[idx]),ladders,idx+1,maxIdx,dp));
//             }
//             if(ladders-1>=0){
//                 maxIdx=max(maxIdx,idx+1);
//                 dp[idx][bricks][ladders-1]=maxIdx;
//                 maxIdx=max(maxIdx,helper(heights,bricks,ladders-1,idx+1,maxIdx,dp));
//             }
//         }
//         return maxIdx;
//     }
//     int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
//         int idx=0,maxIdx=0;
//         unordered_map<int,unordered_map<int,unordered_map<int,int>>> dp;
//         return helper(heights,bricks,ladders,idx,maxIdx,dp);
//     }
////////////////////////////////////////////////////////////////

    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int val;
        for(int i=0;i<heights.size()-1;i++){
            val=heights[i+1]-heights[i];
            if(val>0){
                //use brick;  -> change taken decision
                bricks-=val;
                pq.push(val);
                if(bricks<0){
                    if(ladders==0) return i;
                    int top=pq.top();
                    pq.pop();
                    bricks+=top;
                    ladders--;
                }
            }
        }
        return heights.size()-1;
    }
};
