//https://leetcode.com/problems/find-good-days-to-rob-the-bank/description/


class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        if(time==0){
            vector<int> result;
            for(int i=0;i<security.size();i++) result.push_back(i);
            return result;
        };
        int l=security.size();
        vector<bool> prefix(l,false);
        vector<bool> suffix(l,false);
        int trackerP=1,trackerS=1;
        prefix[0]=true;
        suffix[l-1]=true;
        for(int i=1;i<l;i++){
            if(security[i-1]>=security[i]){
                if(trackerP>=time) prefix[i]=true;
                trackerP++;
            }
            else trackerP=1;

            if(security[l-i]>=security[l-i-1]){
                if(trackerS>=time) suffix[l-i-1]=true;
                trackerS++;
            }
            else trackerS=1;


        }
        vector<int> result;
        for(int i=time;i<l-time;i++){
            if(prefix[i]==1 && suffix[i]==1) result.push_back(i);
        }
        return result;

    }
};
