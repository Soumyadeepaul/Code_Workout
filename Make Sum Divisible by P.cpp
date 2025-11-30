//https://leetcode.com/problems/make-sum-divisible-by-p/?envType=daily-question&envId=2025-11-30


class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total=0;
        for(int i:nums){
            total=(long long) total+i;
        }
        int removeValue=total%p;
        if(removeValue==0) return 0;
        
        unordered_map<int,int> map;
        map[0]=-1;//edge case
        long long currSum=0,prefix,result=nums.size();
        for(int i=0;i<nums.size();i++){
            // x=currSum-remainder
            currSum=((long long)currSum+nums[i])%p;
            prefix=(currSum-removeValue+p)%p; // +p for not to get negetive value
            if(map.count(prefix)){
                result=min(result,(long long)i-map[prefix]);
            }
            map[currSum]=i;
        }
        return result!=nums.size() ? result : -1;

    }
};
