//https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-ii/description/


class Solution {
public:
    int helper(vector<int>& A, vector<int>& AD, vector<int>& B, vector<int>& BD){
        int AEarliestFinish=INT_MAX;
        for(int i=0;i<A.size();i++) AEarliestFinish=min(AEarliestFinish,A[i]+AD[i]);
        int result=INT_MAX;

        for(int i=0;i<B.size();i++){
            result=min(result,max(AEarliestFinish,B[i])+BD[i]);
        }
        return result;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        return min(helper( landStartTime,  landDuration,  waterStartTime,  waterDuration), helper( waterStartTime,  waterDuration,  landStartTime,  landDuration));
    }
};
