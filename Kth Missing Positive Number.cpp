//https://leetcode.com/problems/kth-missing-positive-number/description/?envType=study-plan-v2&envId=binary-search


class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int count=0;
        int idx=0;
        int l=arr.size();
        int i;
        for(i=1;i<10000;i++){
            while(idx<l && i>arr[idx]){
                idx++;
            }
            if(idx<l && arr[idx]!=i)
                count++;
            if(count==k) return i;
            if(idx==l) break;
        }
        
        while(count!=k-1){
            count++;
            i++;
        }
        return i;
    }
};
