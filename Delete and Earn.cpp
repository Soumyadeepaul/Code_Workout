//https://leetcode.com/problems/delete-and-earn/description/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> count;
        for(int &i:nums){
            count[i]++;
        }
        int maxi=*max_element(nums.begin(),nums.end());
        vector<int> houseRoberry(maxi+1,0);
        for(auto &p:count) houseRoberry[p.first]=(p.first*p.second);

        if(houseRoberry.size()>1){
            houseRoberry[1]=max(houseRoberry[1],houseRoberry[0]);
        }
        for(int i=2;i<maxi+1;i++){
            houseRoberry[i]=max(houseRoberry[i]+houseRoberry[i-2], houseRoberry[i-1]);
        }
        return houseRoberry[houseRoberry.size()-1];
    }
};
