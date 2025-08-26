//https://www.geeksforgeeks.org/problems/subset-sums2234/1&selectedLang=python3


#include <numeric>
class Solution {
  public:
    void sums(vector<int> &arr,vector<int> bucket,int index,int n,vector<int> &result){
        if(index==n){
            int val=accumulate(bucket.begin(),bucket.end(),0);
            result.push_back(val);
            return ;
        }
        bucket.push_back(arr[index]);
        sums(arr,bucket,index+1,n,result);
        bucket.pop_back();
        sums(arr,bucket,index+1,n,result);
        return;
        
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int> bucket;
        vector<int> result;
        sums(arr,bucket,0,arr.size(),result);
        return result;
        
    }
};
