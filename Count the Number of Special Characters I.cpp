//https://leetcode.com/problems/count-the-number-of-special-characters-i/description/?envType=daily-question&envId=2026-05-26


class Solution {
public:
    int numberOfSpecialChars(string word) {
       int count=0;
       
       vector<vector<bool>> map(26, vector<bool>(3));

        for(char c:word){
            if(c>='a'){
                map[c-'a'][0]=1;
                if(map[c-'a'][1]==1 && map[c-'a'][2]==0) {
                    count++;
                    map[c-'a'][2]=1;
                }
            }
            else if(c<='Z'){
                map[c-'A'][1]=1;
                if(map[c-'A'][0]==1 && map[c-'A'][2]==0){
                    count++;
                    map[c-'A'][2]=1;
                }
            }
        }
        return count; 
    }
};
