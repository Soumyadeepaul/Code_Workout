//https://leetcode.com/problems/minimum-absolute-difference/description/?envType=daily-question&envId=2026-01-26

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> result;
        sort(arr.begin(),arr.end());
        int minDiff=INT_MAX;
        for(int i=1;i<arr.size();i++){
            minDiff=min(minDiff,arr[i]-arr[i-1]);
        }
        for(int i=1;i<arr.size();i++){
            if(arr[i]-arr[i-1]==minDiff){
                result.push_back({arr[i-1],arr[i]});
            }
        }
        return result;
    }
};
