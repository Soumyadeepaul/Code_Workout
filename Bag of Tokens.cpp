//https://leetcode.com/problems/bag-of-tokens/description/


class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int score=0;
        int i=0,j=tokens.size()-1;
        int result=0;
        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i];
                score+=1;
                i++;
            }
            else if(power<tokens[j] && score>0){
                power+=tokens[j];
                score--;
                j--;
            }
            else break;
            result=max(result,score);
        }
        return result;
    }
};
