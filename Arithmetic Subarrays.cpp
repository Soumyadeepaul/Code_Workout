//https://leetcode.com/problems/arithmetic-subarrays/description/

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> result(l.size(),true);
        int i=0;
        int start;
        int stop;
        while(i<l.size()){
            start=l[i];
            stop=r[i];
            vector<int> arr;
            for(;start<=stop;start++){
                arr.push_back(nums[start]);
            }
            sort(arr.begin(),arr.end());
            int r=arr[1]-arr[0];
            for(int j=1;j<arr.size()-1;j++){
                if(arr[j+1]-arr[j]!=r){
                    result[i]=false;
                    break;
                }
            }
            i++;
        }
        return result;
    }
};
