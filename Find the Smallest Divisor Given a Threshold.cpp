//https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/


class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start=1, end=*max_element(nums.begin(),nums.end());
        int mid;
        while(start<=end){
            mid=(start+end)/2;
            int summ=0;
            for(int i:nums){
                summ+=i/mid;
                if(i%mid) summ++;
                if(summ>threshold) break;
            }
            if(summ>threshold) start=mid+1;
            else end=mid-1;
        }

        return start;
    }
};
