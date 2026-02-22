//https://leetcode.com/contest/weekly-contest-490/problems/check-digitorial-permutation/description/


class Solution {
public:
    bool permute(string a, string b, int idx){
        if(a==b) return true;
        for(int i=idx;i<a.size();i++){
            swap(a[i],a[idx]);
            if(permute(a,b,idx+1))return true;
            swap(a[i],a[idx]);
        }
        return false;
    }
    bool isDigitorialPermutation(int n) {
        vector<int> store={1,1,2,6,24,120,720,5040,40320,362880};
        int result=0;
        int backUp=n;
        while(n){
            result+=store[n%10];
            n/=10;
        }
        if(to_string(result).size()!=to_string(backUp).size()) return false;
        
        return (result==backUp) ? true: permute(to_string(result),to_string(backUp),0);
    }
};
