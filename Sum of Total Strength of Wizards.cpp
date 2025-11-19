//https://leetcode.com/problems/sum-of-total-strength-of-wizards/description/



// #include <bits/stdc++.h>
// using namespace std;

class Solution {
public:
    int totalStrength(vector<int>& strength) {
        int n=strength.size();
        vector<vector<pair<int,int>>> dp(n,(vector<pair<int,int>> (n,{0,0})));
        int result=0,i;
        int p=pow(10,9)+7;
        for(int gap=0;gap<n;gap++){
            for(i=0;i<n-gap;i++){
                int j=i+gap;
                if(j==i){
                    dp[i][j]={strength[i],strength[i]};
                    result=(result+strength[i]*strength[i])%p;
                }
                else{
                    int mini=min(strength[j],dp[i][j-1].first);
                    int summ=dp[i][j-1].second+strength[j];
                    dp[i][j]={mini,summ};
                    result=(result+(mini*summ))%p;
                    
                }
            }
        }
        return result;
    }
};

// int main(){
//     int i,n;
//     cout<<"Enter the number of wizards: ";
//     cin>>n;
//     vector<int> strength(n);
//     for(i=0;i<n;i++)
//         cin>>strength[i];
//     Solution s;
//     cout<<s.totalStrength(strength);
//     return 0;
// }
