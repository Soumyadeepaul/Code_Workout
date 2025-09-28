//https://leetcode.com/problems/find-right-interval/?envType=study-plan-v2&envId=binary-search

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        //
        // int l=intervals.size();
        // vector<int> result(l,-1);
        // int dis;
        // for(int i=0;i<l;i++){
        //     dis=INT_MAX;
        //     for(int j=0;j<l;j++){
        //         if(intervals[i][1]<=intervals[j][0] && intervals[j][0]-intervals[i][0]<dis){
        //             result[i]=j;
        //             dis=intervals[j][0]-intervals[i][0];
        //         }
        //     }
        // }
        // return result;
        ////////////////////////////////////////////////////////
        int l=intervals.size();
        vector<vector<int>> start(l);
        vector<int> end(l);
        vector<int> result(l,-1);
        for(int i=0;i<l;i++){
            start[i].push_back(intervals[i][0]);
            start[i].push_back(i);
            end[i]=intervals[i][1];
        }
        sort(start.begin(),start.end());
        for(int i=0;i<l;i++){
            int low=0;
            int high=l;
            int mid;
            while(low<high){
                mid=low+(high-low)/2;
                if(start[mid][0]-end[i]==0){
                    result[i]=start[mid][1];
                    break;
                }
                else if(start[mid][0]-end[i]>0){
                    result[i]=start[mid][1];
                    high=mid;
                }
                else{
                    low=mid+1;
                }
            }
        }
        return result;
    }
};
