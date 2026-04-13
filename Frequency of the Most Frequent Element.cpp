//https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/


class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=nums.size();
        int j=0,i=0;
        int back=j;
        int result=0;
        while(j<l){
            if(j+1<l && nums[j+1]==nums[j]){
                j++;
                continue;
            }
            int cost=0;
            back=i;
            while(back>-1){
                int add=nums[j]-nums[back];
                if(cost+add<=k){
                    cost+=add;
                    back--;
                }
                else break;
            }
            result=max(result,j-back);
            j++;
            i=j;

        }
        return result;
    }
};


