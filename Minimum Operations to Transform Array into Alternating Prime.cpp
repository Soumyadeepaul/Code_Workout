//https://leetcode.com/contest/biweekly-contest-180/problems/minimum-operations-to-transform-array-into-alternating-prime/description/


class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<bool> store(100000+100,1);
        store[0]=0;
        store[1]=0;
        for(int i=2;i<store.size();i++){
            if(store[i]==0) continue;
            else{
                for(long long j=i<<1;j<store.size();j+=i){
                    store[j]=0;
                }
            }
        }
        int suffix=0;
        vector<int> next(100000+100,0);
        for(int i=store.size()-1;i>-1;i--){
            if(!store[i]) ++suffix;
            else suffix=0;
            next[i]=suffix;
        }
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(i&1){
                if(store[nums[i]]==1 && nums[i]==2) count+=2;
                else if(store[nums[i]]==1) count+=1;
            }
            else{
                if(store[nums[i]]==0) count+=next[nums[i]];
            }
        }
        return count;
    }
};
