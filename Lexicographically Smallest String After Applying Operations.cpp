//https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/description/?envType=daily-question&envId=2025-10-19


class Solution {
public:
    string addOp(string s,int &a){
        for(int i=1;i<s.size();i+=2){
            s[i] = (((stoi(string(1,s[i])))+a)%10) + '0';
        }
        return s;
    }
    string rotateOp(string s,int &b){
        string x=s.substr(s.size()-b,b);
        s=x+s.substr(0,s.size()-b);
        return s;
    }
    void op(string s,int a,int b,unordered_set<string> &map){
        if(map.find(s)==map.end()){
            map.insert(s);
            string s1=addOp(s,a);
            string s2=rotateOp(s,b);
            op(s2,a,b,map);
            op(s1,a,b,map);
            
            
        }
        else return;
    }
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> map;
        op(s,a,b,map);
        return *min_element(map.begin(),map.end());
    }
};
