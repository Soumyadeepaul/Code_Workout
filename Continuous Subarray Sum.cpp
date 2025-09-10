//https://leetcode.com/problems/continuous-subarray-sum/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;//remainder,index
        //intution is while adding numbers if same number as remainder arrives.. then 
        // the number k or multiple of k has been added
        // so the index diff. of previous and now must be >1;

        map.insert({0,-1}); //-> when we will get our 1st zero as rem ... if no zero present in map
        // then it will just get inserted.... but we need to check the length...
        //[21,7] k=7
        // when 21 will come it must check will something as 21%7=0... but length =1
        int summ=0;
        int rem;
        for(int i=0;i<nums.size();i++){
            summ=nums[i]+summ;
            rem=summ%k;
            if(map.find(rem)==map.end()){
                map.insert({rem,i});
            }
            else{
                if(i-map[rem]>1){
                    return true;
                }
                // else{
                //     map[rem]=i;
                // }
            }
        }
        return false;
    }
};
