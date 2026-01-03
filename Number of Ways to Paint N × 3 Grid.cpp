//https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/description/?envType=daily-question&envId=2026-01-03
//https://www.youtube.com/watch?v=W-WvItFiWX8

//ABA (yellow-red-yellow)                   //ABC (yellow-red-green)
//BCB - CBC 2 ways                          //BCB - CAC - BAB  3ways
//ACB - CAB 2 ways                          //BCA - CAB        2ways
class Solution {
public:
    int mod=pow(10,9)+7;
    pair<int,int> helper(int i){
        if(i==1) return {6,6};
        pair<int,int> p=helper(i-1);
        long long a= ((long long)3*p.first)%mod+((long long)2*p.second)%mod;
        long long b= ((long long)2*p.first)%mod+((long long)2*p.second)%mod;
        return {a,b};
    }
    int numOfWays(int n) {
        pair<int,int> p=helper(n);
        return ((long long)p.first+p.second)%mod;
    } 
};
