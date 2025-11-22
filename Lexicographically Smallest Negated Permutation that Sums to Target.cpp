//https://leetcode.com/contest/biweekly-contest-170/problems/lexicographically-smallest-negated-permutation-that-sums-to-target/description/

//TLE

class Solution {
private:
    bool helper(vector<int> &arr,int summ,vector<int> &stack,int idx,int &n, long long & target){
        if(summ+2*accumulate(stack.begin(),stack.end(),0)==target){
            return true;
        }
        if(idx==n){
            return false;
        }
        stack.push_back(-arr[idx]);
        if(helper(arr,summ,stack,idx+1,n,target)==true) return true;
        stack.pop_back();
        if(helper(arr,summ,stack,idx+1,n,target)==true) return true;
        return false;
    }
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        vector<int> arr(n);
        for(int i=1;i<=n;i++) arr[i-1]=i;
        reverse(arr.begin(),arr.end());
        int summ=(n*(n+1))/2;
        if(summ<target || -summ>target) return {};
        vector<int> stack;
        bool f=helper(arr,summ,stack,0,n,target);
        if(f){
            cout<<"1";
            reverse(arr.begin(),arr.end());
            for(int i:stack){
                arr[abs(i)-1]=0;
            }
            sort(stack.begin(),stack.end());
            vector<int>result(stack.begin(),stack.end());
            for(int i:arr){
                if(i!=0) result.push_back(i);
            }
            return result;
        }
        return {};
    }
};©leetcode
