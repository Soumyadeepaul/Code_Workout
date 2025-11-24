//https://leetcode.com/problems/binary-prefix-divisible-by-5/description/


class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        unsigned long long i=0,l=nums.size();
        vector<bool> result(l,false);
        for(int j=0;j<l;j++){
            i=(unsigned long long)i*2+nums[j];
            //cout<<i<<endl;
            if(i%5==0){
                result[j]=true;
                i=0;  // when any number is divisible by 5... it will always be divisible by 5 no matter how many times we multiply with any number. So no meaining to accumulate
            }
        }
        return result;
    }
};
