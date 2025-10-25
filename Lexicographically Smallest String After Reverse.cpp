//https://leetcode.com/contest/biweekly-contest-168/problems/lexicographically-smallest-string-after-reverse/description/


class Solution {
public:
    string lexSmallest(string s) {
        int k=1;
        string minimum=s;
        int l=s.size();
        string temp=s;
        while(k<l){
            reverse(temp.begin(),temp.begin()+k);
            minimum=min(minimum,temp);
            temp=s;
            reverse(temp.end()-k-1,temp.end());
            minimum=min(minimum,temp);
            temp=s;
            k++;
        }
        return minimum;
    }
};©leetcode
