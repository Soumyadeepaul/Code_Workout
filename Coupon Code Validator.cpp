//https://leetcode.com/problems/coupon-code-validator/description/?envType=daily-question&envId=2025-12-13


class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        priority_queue<pair<string,string>,vector<pair<string,string>>, greater<pair<string,string>>> pq;
        set<string> valid;
        valid.insert("restaurant");
        valid.insert("grocery");
        valid.insert("pharmacy");
        valid.insert("electronics");

        for(int i=0;i<code.size();i++){
            if(isActive[i]==false) continue;
            if(code[i]=="") continue;
            if(valid.find(businessLine[i])==valid.end()) continue;
            pq.push({businessLine[i],code[i]});
        }
        vector<string> result;
        bool invalid;
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            invalid=false;
            for(char i:p.second){
                if((i>='a' && i<='z') || (i>='A' && i<='Z') || (i>='0' && i<='9') || i=='_'){}
                else {invalid=true;
                break;}
            }
            if(invalid==false) result.push_back(p.second);
        }
        return result;

    }
};
