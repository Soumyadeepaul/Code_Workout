//https://leetcode.com/contest/weekly-contest-474/problems/maximum-product-of-three-elements-after-one-replacement/description/


class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l=nums.size();
        vector<int> nNew={nums[0],nums[1],nums[l-1],nums[l-2]};
        long long maxi=INT_MIN;
        int p=pow(10,5);
        for(int i=0;i<4;i++){
            for(int j=i+1;j<4;j++){
                long long store=(long long)nNew[i]*nNew[j];
                if(store>0){
                    maxi=max(maxi,store*p);
                }
                else{
                    maxi=max(maxi,-store*p);
                }
            }
        }
        return maxi;
        
    }
};©leetcode
