//https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/


class Solution {
public:
    int maxOperations(string s) {
        int count=0;
        int countStacked0=0;
        int countStacked1=0;
        s+='1';//if last element be 0.. just to push back all 1's to end
        for(int i=0;i<s.size();i++){
            if(s[i]=='1' && countStacked0==0) countStacked1++;
            else if(s[i]=='0') countStacked0++;
            else{
                countStacked0=0;
                count+=countStacked1;
                countStacked1++;
            }

        }
        return count;
    }
};
