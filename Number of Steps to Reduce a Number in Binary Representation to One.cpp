//https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/?envType=daily-question&envId=2026-02-26


class Solution {
public:
    void helper(string &s,int &l){
        int k=s.size()-1;
        bool found=0;
        while(k!=-1){
            if(s[k]=='0'){
                s[k]='1';
                found=1;
                break;
            }
            s[k]='0';
            k--;
        }
        if(found==1) return;
        s='1'+s;
        l++;
    }
    int numSteps(string s) {
        int count=0,l=s.size()-1;
        while(l!=0){
            if(s[l]=='1'){
                count+=1;
                helper(s,l);
            }
            else{
                count+=1;
                s.pop_back();
                l--;
            }
        }
        if(s[0]=='0') count++;
        return count;
    }
};
