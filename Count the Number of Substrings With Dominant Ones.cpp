//https://leetcode.com/problems/count-the-number-of-substrings-with-dominant-ones/description/?envType=daily-question&envId=2025-11-15


class Solution {
public:
    int helper(string &s,vector<int> &nextZero,int &n){
        int dominating=0;
        int count0=0,count1;
        for(int i=0;i<n;i++){
            count0=0;
            if(s[i]=='0') count0=1;
            int j=i;
            int cal=pow(count0,2);
            while(cal<=n){
                cal=pow(count0,2);
                int next0=n;
                if(j<n)
                    next0=nextZero[j];
                count1=next0-i-count0;
                if(count1>=cal){
                    dominating+=min(next0-j,
                    count1-cal+1);
                }
                j=next0;
                count0++;
                if(j==n) break;
            }
        }
        return dominating;
    }
    int numberOfSubstrings(string s) {
        int n=s.size();
        vector<int> nextZero(n,n);
        for(int i=n-2;i>-1;i--){
            if(s[i+1]=='0') nextZero[i]=i+1;
            else nextZero[i]=nextZero[i+1];
        }
        return helper(s,nextZero,n);
    }
};
