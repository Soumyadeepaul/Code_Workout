//https://leetcode.com/problems/number-of-substrings-with-only-1s/description/?envType=daily-question&envId=2025-11-16

class Solution {
public:
    int numSub(string s) {
        int i=0;
        int j=0;
        s+='0'; //for last subarray calculation
        int l=s.size();
        unsigned count=0;
        int mod=pow(10,9)+7;
        int n;
        while(j<l){
            if(s[j]=='0'){
                if(s[i]=='1'){
                    n=j-i;
                    if(n%2==0){
                        count+=(unsigned)(n/2)*(n+1) % mod;
                    }
                    else{count+=(unsigned)((n+1)/2)*(n) % mod;}
                }
                i=j;
            }
            else{
                if(s[i]=='0') i=j;
            }
            j++;
        }
        return count;
    }
};
