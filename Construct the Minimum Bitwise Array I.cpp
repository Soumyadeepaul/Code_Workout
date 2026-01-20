//https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/description/?envType=daily-question&envId=2026-01-20


class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&1){
                bool found=0;
                for(int j=1;j<10;j++){
                    if(nums[i]==(2<<j)-1){
                        
                        ans.push_back(nums[i]/2);
                        found=1;
                        break;
                    }
                }
                if(found==0) {
                    for(int j=1;j<nums[i];j++){
                        if(nums[i]==(j|(j+1))){
                            ans.push_back(j);
                            break;
                        }
                    }
                }
            }
            else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
