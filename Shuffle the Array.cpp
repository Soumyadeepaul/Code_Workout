//https://leetcode.com/problems/shuffle-the-array/description/?envType=problem-list-v2&envId=dsa-linear-shoal-array-i

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result(2*n);
        int i=0,j=n;
        bool counter=0;
        int idx=0;
        while(i<n || j<2*n){
            if(counter==0){
                result[idx++]=nums[i++];
                counter=1;
            }
            else{
                result[idx++]=nums[j++];
                counter=0;
            }
        }
        return result;
    }
};
