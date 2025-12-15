//https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/description/?envType=daily-question&envId=2025-12-15

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        //sliding window
        long long count=0;
        int i=0,j=1;
        prices.push_back(INT_MAX);
        int l=prices.size();
        while(j<l){
            if(prices[j-1]-1==prices[j]){
                j++;
            }
            else{
                int n=j-i;
                if(n&1) count+=(long long)n*((n+1)/2);
                else count+=(long long)(n/2)*(n+1);
                i=j;
                j++;
            }
        }
        return count;
    }
};
