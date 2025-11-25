//https://leetcode.com/problems/contiguous-array/?envType=problem-list-v2&envId=prefix-sum


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        //convert 0 to -1
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) nums[i]=-1;
        }
        unordered_map<int,int>  map; //added value, 1st pos
        int summ=0,result=0;
        for(int i=0;i<nums.size();i++){
            summ+=nums[i];
            if(summ==0) result=i+1; // when summ up to 0... its obivous that its the largest length
            else if(map.count(summ)){
                result=max(result,i-map[summ]); // suppose -2 1st arrived at index 1 and last arrived at index 8.... we have to consider from index 3 to 8
            }
            else{
                map[summ]=i;
            }
        }
        return result;
        
    }
};
