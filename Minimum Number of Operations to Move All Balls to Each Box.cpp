//https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/

class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> result;
        int moves;
        int l=boxes.size();
        for(int i=0;i<l;i++){
            moves=0;
            for(int j=0;j<l;j++){
                if(i!=j){
                    if(boxes[j]=='1'){
                        moves+=abs(j-i);
                    }
                }
            }
            result.push_back(moves);
        }
        return result;

    }
};
