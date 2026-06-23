//https://leetcode.com/problems/maximum-energy-boost-from-two-drinks/description/


class Solution {
public:
    vector<vector<vector<long long>>>dp;
    long long helper(vector<int>& energyDrinkA, vector<int>& energyDrinkB, int idx, bool switched, bool A){
        if(idx==energyDrinkB.size()){
            return 0;
        }

        if(dp[idx][A][switched]!=-1) return dp[idx][A][switched];

        long long ans=0;
        if(switched){
            ans=helper(energyDrinkA,energyDrinkB, idx+1,true,!A);//switch again
            long long val=helper(energyDrinkA,energyDrinkB, idx+1,false,A);
            if(val>ans) ans=val; //dont switch but in cooldown
        }
        else{
            if(A){
                ans=helper(energyDrinkA,energyDrinkB, idx+1,true,!A)+energyDrinkA[idx]; //taken and switched
                long long val=helper(energyDrinkA,energyDrinkB, idx+1,false,A)+energyDrinkA[idx];
                if(val>ans) ans=val;// taken and not switched
            }
            else{
                ans=helper(energyDrinkA,energyDrinkB, idx+1,true,!A)+energyDrinkB[idx];
                long long val=helper(energyDrinkA,energyDrinkB, idx+1,false,A)+energyDrinkB[idx];
                if(val>ans) ans=val;// taken and not switched
            }
        }
        return dp[idx][A][switched]=ans;
    }
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        dp.assign(energyDrinkA.size(),vector<vector<long long>> (2,vector<long long>(2,-1)));
        return max(helper(energyDrinkA,energyDrinkB,0,0,1),helper(energyDrinkA,energyDrinkB,0,0,0));
    }
};
