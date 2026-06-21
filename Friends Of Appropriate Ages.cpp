//https://leetcode.com/problems/friends-of-appropriate-ages/description/


class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(),ages.end());
        int count=0;
        for(int i=0;i<ages.size();i++){
            int mini=0.5*ages[i]+7;
            int maxi=ages[i];
            mini=min(mini,maxi);
            if(ages[i]>=100){
                mini=min(100,mini);
            }

            auto low=upper_bound(ages.begin(),ages.end(),mini)-ages.begin();
            auto high=upper_bound(ages.begin(),ages.end(),maxi)-ages.begin();

            int val=high-low-1;
            count+=max(0,val);
        }
        return count;
    }
};
