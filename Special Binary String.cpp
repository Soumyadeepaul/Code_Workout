//https://leetcode.com/problems/special-binary-string/description/?envType=daily-question&envId=2026-02-20


class Solution {
public:
    string helper(string rec){
        int i=0,j=0;
        int summ=0;
        vector<string> store;
        while(j<rec.size()){
            if(rec[j]=='1') summ++;
            else if(rec[j]=='0') summ--;
            if(summ==0){
                store.push_back("1"+helper(rec.substr(i+1,j-i))+"0");
                i=j+1;
            }
            j++;
        }
        sort(store.begin(),store.end(),greater());
        string create="";
        for(string c: store) create+=c;
        return create;
    }
    string makeLargestSpecial(string s) {
        return helper(s);
    }
};
