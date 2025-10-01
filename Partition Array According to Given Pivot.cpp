//https://leetcode.com/problems/partition-array-according-to-given-pivot/

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> left;
        vector<int> right;
        int count=0;
        int l=nums.size();
        for(int i=0;i<l;i++){
            if(nums[i]<pivot) left.push_back(nums[i]);
            else if(nums[i]==pivot) count++;
            else right.push_back(nums[i]);
        }
        while(count!=0){
            left.push_back(pivot);
            count--;
        }
        left.insert(left.end(),right.begin(),right.end());
        return left;
    }
};
