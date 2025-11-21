//https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        //intution
        // abacba
        // start from a then b then c...
        // for each case j should come from the end.. j--
        // because   a.......a    will have maximum no. of palindrom    as xyx... y changes and break
        // we will have duplicate as abba.... here aba and aba will be counted
        // therefore used distinct array and looped between i+1 j-1;
        int l=s.size();
        int count=0;
        int j=0;
        vector<int> helper(26,0);
        vector<int> distinct(26,0);
        for(int i=0;i<l;i++){
            j=l-1;
            distinct.resize(26,0);
            while(i<j){
                if(helper[s[i]-'a']==1)break;
                if(s[i]==s[j]){
                    int c=0;
                    for(int x=i+1;x<j;x++){
                        if(distinct[s[x]-'a']==0){
                            distinct[s[x]-'a']=1;
                            c++;
                        }
                    }
                    count+=c;
                    helper[s[i]-'a']=1;
                    break;
                }
                j--;
            }
            distinct.clear();
        }
        return count;
    }
};//
