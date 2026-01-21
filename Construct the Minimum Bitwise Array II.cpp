//https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/description/?envType=daily-question&envId=2026-01-21


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
                    int d=1;
                    int res=-1;
                    while((nums[i]&d)!=0){
                        res=nums[i]-d;
                        cout<<res<<endl;
                        d=d<<1;
                    }
                    ans.push_back(res);
                }

                
            }
            else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
