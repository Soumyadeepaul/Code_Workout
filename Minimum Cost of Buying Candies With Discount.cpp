//https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/description/?envType=daily-question&envId=2026-06-01


class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int result=0;

        for(int i=cost.size()-1;i>-1;i-=3){
            result+=cost[i];
            if(i!=0) result+=cost[i-1];
        }

        return result;
    }
};
