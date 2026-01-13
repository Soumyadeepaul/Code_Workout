//https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/description/?envType=problem-list-v2&envId=recursion


class Solution {
public:
    string invert(string s){
        string s1="";
        for(char i:s){
            if(i=='0') s1+='1';
            else s1+='0';
        }
        return s1;
    }
    string rev(string s){
        reverse(s.begin(),s.end());
        return s;
    }
    string helper(int &n,int &k, int i, string s){
        if(i==1) return "0";
        string store=helper(n,k,i-1,s);
        s+=store+"1"+rev(invert(store));
        return s;
    }
    char findKthBit(int n, int k) {
        int i=n;
        string s="";
        s=helper(n,k,i,s);
        return s[k-1];
    }
};
