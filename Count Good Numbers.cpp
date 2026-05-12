//https://leetcode.com/problems/count-good-numbers/description/



class Solution {
public:
    typedef long long ll;
    const int prime=4,even=5;
    int mod=1e9+7;
    ll power(ll half, int n){
        ll val=1,p=n;
        while(half>0){
            int rem=half%2;
            half>>=1;
            if(rem==1) val=(1ll*val*p)%mod;
            p=(1ll*p*p)%mod;
        }
        return val;
    }
    int countGoodNumbers(long long n) {
        ll result=0;
        ll even=(n+1)/2,odd=n/2;
        result=(1ll*power(even,5)*power(odd,4))%mod;
        return result;
    }  
};
