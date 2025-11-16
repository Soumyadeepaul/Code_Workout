//https://leetcode.com/contest/weekly-contest-476/problems/count-stable-subarrays/description/


//TLE


class Solution {
public:
    long long helper(vector<int> &nums,int l,int r){
        //bf
        long long count=0;
        int j=l;
        int i=l;
        int previous=0;
        while(j<=r){
            if(i==j){
                count++;
                j++;
                previous=1;
            }
            else if(nums[j]>=nums[j-1]){
                int n=j-i+1;
                int cal=(n*(n+1))/2;
                count+=cal - previous; //a U b = a + b - a intersection b
                previous=cal;
                j++;
            }
            else{
                i=j;
            }
        }
        return count;
        
    }
    vector<long long> countStableSubarrays(vector<int>& nums, vector<vector<int>>& queries) {
        int l=queries.size();
        vector<long long> result(l);
        for(int i=0;i<l;i++){
            result[i]=helper(nums,queries[i][0],queries[i][1]);   
        }
        return result;
            
    }
};©leetcode
