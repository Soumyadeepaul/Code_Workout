//https://leetcode.com/problems/form-array-by-concatenating-subarrays-of-another-array/description/?envType=problem-list-v2&envId=string-matching


class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        // sliding window
        int l=nums.size();
        int i,j=0,gL,lastInitialMatch=0;
        for(vector<int> g:groups){
            i=0,gL=g.size();
            while(i<gL && j<l){ // j will start from next location after finding a group   lets to disjoint feature
                if(g[i]==nums[j]){ // if match found
                    if(i==0) lastInitialMatch=j;
                    i++;
                    j++;
                }
                else{
                    i=0;   // start from initial of that group
                    j=++lastInitialMatch;
                }
                
            }
            if(i!=gL) return false;
            else lastInitialMatch=j; // when next group check will start... it shouldnt get updated with old groups initial index check
        }
        return true;

    }
};
