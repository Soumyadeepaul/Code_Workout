//https://leetcode.com/problems/count-days-without-meetings/description/


class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        
        sort(meetings.begin(),meetings.end());
        int end=meetings[0][1];
        int count=meetings[0][0];
        for(int i=1;i<meetings.size();i++){
            if(end<meetings[i][0]){ //there is a gap
                count+=(meetings[i][0]-end-1);
                end=meetings[i][1];
            }
            else{
                end=max(end,meetings[i][1]);
            }
        }
        count+=days-end-1;
        return count;
    }
};
