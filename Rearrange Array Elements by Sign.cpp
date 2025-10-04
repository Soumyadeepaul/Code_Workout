//https://leetcode.com/problems/rearrange-array-elements-by-sign/


class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int l=nums.size();
        vector<int> result;
        queue<int> negIdx;
        for(int i=0;i<l;i++){
            if(nums[i]>0){
                result.push_back(nums[i]);
            }
            else{
                negIdx.push(i);
            }
        }
        int idx=1;
        while(!negIdx.empty()){
            result.insert(result.begin()+idx,nums[negIdx.front()]);
            negIdx.pop();
            idx+=2;
        }
        return result;
    }
};
