//https://leetcode.com/problems/two-best-non-overlapping-events/description/?envType=daily-question&envId=2025-12-23

class Solution {
public:
    // static bool cmp(const vector<int> &a,const vector<int> &b){
    //     if(a[1]>b[1]) return true;
    //     return false;
    // }
    int maxTwoEvents(vector<vector<int>>& events) {
        //TLE
        // sort(events.begin(),events.end());
        // int result=INT_MIN;
        // for(int i=0;i<events.size();i++){
        //     result=max(result,events[i][2]);
        //     for(int j=i+1;j<events.size();j++){
        //         if(events[i][1]>=events[j][0]){}
        //         else{
        //             result=max(result,events[i][2]+events[j][2]);
        //         }
        //     }
        // }   
        // return result;
        //////////////////////////////////////////
        //MLE + TLE
        // sort(events.begin(),events.end(),cmp);
        // int result=INT_MIN;
        // unordered_map<int,int> dp;
        // for(int i=0;i<events.size();i++){
        //     dp[events[i][0]]=max(dp[events[i][0]],events[i][2]);
        //     if(i+1!=events.size()){
        //         for(int j=events[i][0];j>events[i+1][0]-1;j--){
        //             dp[j]=max(max(dp[j],dp[j+1]),events[i][2]);
        //         }
        //     }
        //     result=max(result,dp[events[i][1]+1]+events[i][2]);
        // }

        // return result;
        ///////////////////////////////////


        sort(events.begin(),events.end());
        //bs on events[][i]+1
        int l=events.size();
        vector<int> suffix(l,INT_MIN);
        suffix[l-1]=events[l-1][2];
        for(int i=l-2;i>=0;i--){
            suffix[i]=max(suffix[i+1],events[i][2]);
        }
        int maxi=0;
        for(int i=0;i<l;i++){
            auto it=lower_bound(events.begin(),events.end(),vector<int>{events[i][1]+1,INT_MIN,INT_MIN});
            if(it != events.end()){
                int idx=it-events.begin();
                maxi=max(maxi,events[i][2]+suffix[idx]);
            }
            else maxi=max(maxi,events[i][2]);
        }
        return maxi;
    }
};
