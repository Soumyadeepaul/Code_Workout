//https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/description/


class Solution {
public:
    int minOperations(vector<int>& nums) {
        int length=nums.size();
        set<int> num(nums.begin(),nums.end()); //to remove duplicate
        vector<int> n(num.begin(),num.end());
        num.clear();
        sort(n.begin(),n.end());
        int result=length;
        int r=0;
        int window=0;
        for(int l=0;l<length;l++){
            //nums[l].....nums[l]+length-1;
            while(r<n.size() && n[r]<n[l]+length) r+=1;
            window= r-l;
            result=min(result,length-window);
        }
        return result;
    }
};
