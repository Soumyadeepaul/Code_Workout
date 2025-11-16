//https://leetcode.com/problems/set-mismatch/description/?envType=problem-list-v2&envId=dsa-linear-shoal-array-ii


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        //cyclic sort
        vector<int> result={0,0};
        int i=0;
        while(i<nums.size()){
            if(nums[i]==i+1) i++;
            else{
                int temp=nums[nums[i]-1];
                if(nums[nums[i]-1]==nums[i]){
                    result[0]=nums[i];
                    i++;
                }
                else{
                    nums[nums[i]-1]=nums[i];
                    nums[i]=temp;
                }
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1){
                result[1]=i+1;
                break;
            }
        }
        return result;
    }
};
