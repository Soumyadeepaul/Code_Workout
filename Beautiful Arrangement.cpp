//https://leetcode.com/problems/beautiful-arrangement/description/

class Solution {
public:
    int count=0;
    bool check(int a, int b){
        return (a%b==0 || b%a==0);
    }
    void perm(vector<int> arr, int idx){
        if(idx==arr.size())count++;
        for(int i=idx;i<arr.size();i++){
            swap(arr[i],arr[idx]);
            if(check(arr[idx],idx+1)) perm(arr,idx+1);
            swap(arr[i],arr[idx]);
        }
    }
    int countArrangement(int n) {
        vector<int> arr;
        for(int i=1;i<=n;i++) arr.push_back(i);
        perm(arr,0);
        return count;
    }
};
