//https://leetcode.com/problems/camelcase-matching/description/?envType=problem-list-v2&envId=string-matching


class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int l=queries.size();
        vector<bool> result(l,false);
        int pL=pattern.size();
        int x=0,y=0;
        bool found;
        int qSize;
        for(int i=0;i<queries.size();i++){
            x=0;
            y=0;
            found=true;
            qSize=queries[i].size();
            while(y<qSize){
                if(x<pL &&queries[i][y]==pattern[x]){
                    x++;
                }
                else if(queries[i][y]-'A'>=0 && queries[i][y]-'A'<26){
                    found=false;
                    break;
                }
                y++;
            }
            if(found==true && x==pL) result[i]=true;
        }
        return result;
    }
};
