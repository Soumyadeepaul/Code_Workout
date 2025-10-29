//
//https://leetcode.com/problems/maximum-product-of-word-lengths/description/

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int result=0;
        for(int i=0;i<words.size();i++){
            vector<int> dp(26,0);
            for(char k:words[i]){
                dp[k-'a']=1;
            }
            for(int j=i+1;j<words.size();j++){
                bool found=true;
                for(char k:words[j]){
                    if(dp[k-'a']==1){
                        found=false;
                        break;
                    }
                }
                if(found==true){
                    int x=words[i].size()*words[j].size();
                    result=max(result,x);
                }
            }

        }
        return result;
    }
};
