//https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-i/?envType=daily-question&envId=2026-06-02


class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int result=INT_MAX;

        for(int i=0;i<landStartTime.size();i++){
            int end=landStartTime[i]+landDuration[i];
            for(int j=0;j<waterStartTime.size();j++){
                int start=waterStartTime[j];
                int dur=waterDuration[j];
                int total=max(start,end)+dur;
                result=min(total,result);
            }
        }  

        for(int i=0;i<waterStartTime.size();i++){
            int end=waterStartTime[i]+waterDuration[i];
            for(int j=0;j<landStartTime.size();j++){
                int start=landStartTime[j];
                int dur=landDuration[j];
                int total=max(start,end)+dur;
                result=min(total,result);
            }
        } 

        return result; 
    }
};
