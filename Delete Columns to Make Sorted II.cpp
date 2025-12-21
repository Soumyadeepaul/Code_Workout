//https://leetcode.com/problems/delete-columns-to-make-sorted-ii/description/?envType=daily-question&envId=2025-12-21

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        vector<bool> sorted(strs.size(),false);
        int count=0;
        for(int col=0;col<strs[0].size();col++){
            bool deleted=false;
            for(int row=0;row<strs.size()-1;row++){
                if(sorted[row]==false && strs[row][col]>strs[row+1][col]){
                    deleted=true;
                    count++;
                    break;
                }
            }
            if(deleted) continue;
            for(int row=0;row<strs.size()-1;row++){
                sorted[row]=sorted[row] | strs[row][col]<strs[row+1][col];
            }
        }
        return count;
    }
};
