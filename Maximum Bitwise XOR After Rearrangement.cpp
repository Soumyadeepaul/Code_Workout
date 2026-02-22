//https://leetcode.com/contest/weekly-contest-490/problems/maximum-bitwise-xor-after-rearrangement/description/


class Solution {
public:
    string maximumXor(string s, string t) {
        int count1=0;
        for(int i:t){
            if(i=='1') count1++;
        }
        string newT="";
        for(int i:s){
            if(i=='0' && count1!=0){
                newT+='1';
                count1--;
            }
            else newT+='0';
        }
        int idx=s.size()-1;
        while(count1!=0){
            if(newT[idx]=='0'){
                newT[idx]='1';
                count1--;
            }
            idx--;
        }
        string result="";
        for(int i=0;i<s.size();i++){
            if(s[i]!=newT[i]) result+='1';
            else result+='0';
        }
        return result;
    }
};
