//https://leetcode.com/problems/minimum-energy-to-maintain-brightness/description/


class Solution {
public:
    typedef long long ll;
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        //interval merge

        // vector<vector<int>> merge;
        sort(intervals.begin(),intervals.end());
        int start=intervals[0][0];
        int end=intervals[0][1];

        int count=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>end){
                // merge.push_back({start,end});
                count+=end-start+1;
                start=intervals[i][0];
                end=intervals[i][1];
                
            }
            else{
                end=max(end,intervals[i][1]);
            }
        }
        // merge.push_back({start,end});
        count+=end-start+1;

        ll on=(brightness+2)/3;

        return on*count;
    }
};
