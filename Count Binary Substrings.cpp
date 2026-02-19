//https://leetcode.com/problems/count-binary-substrings/description/?envType=daily-question&envId=2026-02-19


class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> consecutive;
        char prev=s[0];
        int count=1;
        for(int i=1;i<s.size();i++){
            if(s[i]==prev){
                count++;
            }
            else{
                consecutive.push_back(count);
                prev=s[i];
                count=1;
            }
        }
        consecutive.push_back(count);
        int result=0;
        for(int i=1;i<consecutive.size();i++){
            result+=min(consecutive[i],consecutive[i-1]);
        }
        return result;

    }
};
