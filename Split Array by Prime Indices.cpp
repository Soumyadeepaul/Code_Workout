//https://leetcode.com/problems/split-array-by-prime-indices/description/?envType=problem-list-v2&envId=vylve876


class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int l=nums.size();
        vector<bool> activatePrime(l,true);
        activatePrime[0]=false;
        activatePrime[1]=false;
        for(int i=2;i<l;i++){
            if(activatePrime[i]==true){
                for(int j=i+i;j<l;j=j+i){
                    activatePrime[j]=false;
                }
            }
        }
        long long a=0,b=0;
        for(int i=0;i<l;i++){
            if(activatePrime[i]==true) a=(long long) a+nums[i];
            else b=(long long)b+nums[i];
        }
        return abs(a-b);
    }
};
