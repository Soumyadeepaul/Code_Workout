//https://leetcode.com/problems/longest-repeating-character-replacement/description/



class Solution {
public:
    int characterReplacement(string s, int k) {
        int result=0;

        unordered_map<char,int> freq;

        int i=0,j=0,l=s.size();


        while(j<l){
            freq[s[j]]++;
            
            //get most freq char
            int maxi=0;
            for(auto p:freq){
                maxi=max(maxi,p.second);
            }
            int slidingWindowSize=j-i+1-maxi; // window - mostfreq... and rest are where k has been used

            while(slidingWindowSize>k){
                freq[s[i]]--;
                maxi=0;
                for(auto p:freq){
                    maxi=max(maxi,p.second);
                }
                i++;
                slidingWindowSize=j-i+1-maxi;
            }
            result=max(result,j-i+1);
            j++;
        }
        return result;


    }
};
