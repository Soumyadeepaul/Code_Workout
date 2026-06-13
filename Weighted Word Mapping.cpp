//https://leetcode.com/problems/weighted-word-mapping/description/?envType=daily-question&envId=2026-06-13



class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result="";
        for(auto w:words){
            int summ=0;
            for(char c:w){
                summ+=weights[c-'a'];
            }
            summ%=26;
            summ=26-summ-1;
            result+='a'+summ;
        }
        return result;
    }
};
