//https://leetcode.com/problems/restore-ip-addresses/description/


class Solution {
public:
    void backtracking(string &s, vector<string>&result,int idx,int count,string currIP){
        if(count==4 && idx==s.size()){
            result.push_back(currIP.substr(0,currIP.size()-1));
            return;
        }
        if(idx==s.size() || count>4) return;
        int to=s.size();
        if(to>idx+3)
            to=idx+3;
        for(int i=idx;i<to;i++){ 
            int val=stoi(s.substr(idx,i-idx+1)); // index, length
            if((val<=255) && (i==idx || s[idx]!='0')){
                backtracking(s,result,i+1,count+1,currIP+to_string(val)+".");
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {

        vector<string> result;
        if(s.size()>12) return result;
        int count=0;
        backtracking(s,result,0,count,"");
        return result;
    }
};
