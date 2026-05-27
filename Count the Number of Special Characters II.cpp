//https://leetcode.com/problems/count-the-number-of-special-characters-ii/description/?envType=daily-question&envId=2026-05-27


class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<vector<int>> map(26, vector<int> (4,0)); // small, cap, added, removed
        int count=0;
        for(char c:word){
            if(c>='a' && c<='z') {
                // if previously counted and small appears again.. remove it
                int x=c-'a';
                if(map[x][0]==1 && map[x][1]==1 && map[x][2]==1 && map[x][3]==0) {
                    count--;
                    map[x][3]=1;
                }
                if(map[x][1]==1) { // already cap present... then think we counted and subed it
                    map[x][2]=1;
                    map[x][3]=1;
                }
                map[x][0]=1;
            }
            else if(c>='A' && c<='Z'){
                int x=c-'A';
                map[x][1]=1;
                if(map[x][0]==1 && map[x][2]==0) { // if small present but not yet counted
                    count++;
                    map[x][2]=1;
                }
            } 
        }
        return count;
    }
};
