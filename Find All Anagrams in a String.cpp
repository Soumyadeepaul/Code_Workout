//https://leetcode.com/problems/find-all-anagrams-in-a-string/description/?envType=problem-list-v2&envId=sliding-window


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        sort(p.begin(),p.end());

        int i=0,l=s.size(),l2=p.size();
        string backUp=s;
        vector<int> result;
        set<char> sett;
        for(char x:p) sett.insert(x);
        while(i+l2<=l){
            if(sett.find(s[i+l2-1])!=sett.end()){
                sort(s.begin()+i,s.begin()+i+l2);
                if(s.substr(i,l2)==p) result.push_back(i);
                s=backUp;
                i++;
            }
            else{
                i=i+l2;
            }
        }
        return result;
    }
};
