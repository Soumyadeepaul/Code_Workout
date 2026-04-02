//https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/


class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> tracker={0,0,0};
        int l=0,r=0, length=s.size();
        int result=0;
        while(r<length){
            if(s[r]=='a') tracker[0]++;
            else if(s[r]=='b') tracker[1]++;
            else if(s[r]=='c') tracker[2]++;

            

            while(tracker[0]>0 && tracker[1]>0 && tracker[2]>0){ //till it the substring becomes invalid
                result+=length-r;
                if(s[l]=='a') tracker[0]--;
                else if(s[l]=='b') tracker[1]--;
                else if(s[l]=='c') tracker[2]--;
                l++;
            }
            r++;
        }
        return result;
    }
};
