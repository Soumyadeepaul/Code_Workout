//https://leetcode.com/contest/weekly-contest-483/problems/word-squares-ii/description/


class Solution {
public:
    void helper(string &top, string &left, string &right, string &bottom, vector<vector<string>> &result){
        if(top[0]==left[0] && top[3]==right[0] && bottom[0]==left[3] && bottom[3]==right[3]){
            result.push_back({top,left,right,bottom});
        }
    }
    vector<vector<string>> wordSquares(vector<string>& words) {
        sort(words.begin(),words.end());
        vector<vector<string>> result;
        string top,left,right,bottom;
        int l=words.size();
        for(int i=0;i<l;i++){
            top=words[i];
            for(int j=0;j<l;j++){
                left=words[j];
                for(int k=0;k<l;k++){
                    right=words[k];
                    for(int m=0;m<l;m++){
                        bottom=words[m];
                        if(top==right || top==left || top==bottom || left==right || left==bottom || right== bottom){ continue;}
                        helper(top,left,right,bottom,result);
                    }
                }
            }
        }
        return result;
        
    }
};
