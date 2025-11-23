//https://leetcode.com/problems/count-sorted-vowel-strings/description/?envType=problem-list-v2&envId=combinatorics


class Solution {
public:
    int countVowelStrings(int n) {
        //initution length of 3.... 
        // begin with a -> a...... so use the value of a when a want the begaining of length 2
        //             ... u...... similary
        //    now 3 length starting with a will be summ of 2a 2e 2i 2o 2u
        vector<int> initial={1,1,1,1,1};
        while(n!=1){
            for(int i=0;i<5;i++){
                initial[i]=accumulate(initial.begin()+i,initial.end(),0);
            }
            n--;
        }
        return accumulate(initial.begin(),initial.end(),0);
    }
};
