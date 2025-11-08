//https://leetcode.com/problems/bulls-and-cows/


class Solution {
public:
    string getHint(string secret, string guess) {
        
        int i=0;
        unordered_map<char,int> presentS;
        vector<char> presentG;
        int bull=0;
        int cow=0;
        while(i<secret.size()){
            if(secret[i]==guess[i]) bull++;
            else{
                presentS[secret[i]]++;
                presentG.push_back(guess[i]);
            }
            i++;
        }
        for(int i:presentG){
            if(presentS.count(i)){
                presentS[i]--;
                cow++;
                if(presentS[i]==0) presentS.erase(i);
            }
        }
        return to_string(bull)+"A"+to_string(cow)+"B";
    }
};
