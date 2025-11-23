//https://leetcode.com/contest/weekly-contest-477/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/description/


class Solution {
public:
    long long sumAndMultiply(int n) {
        string s;
        int summ=0;
        int i;
        while(n){
            i=n%10;
            if(i!=0){
                s=to_string(i)+s;
                summ+=i;
            }
            n/=10;
        }
        long long newN=0;
        for(char j:s){
            newN=(long long)newN*10+(j-'0');
        }
        return (long long)summ*newN;
        
    }
};
