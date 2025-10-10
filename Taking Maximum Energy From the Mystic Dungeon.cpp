//https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/description/?envType=daily-question&envId=2025-10-10

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        //bf
        // int maxi=INT_MIN;
        // int l=energy.size();
        // int summ;
        // bool take;
        // for(int i=0;i<l;i++){
        //     summ=energy[i];
        //     take=true;
        //     for(int j=i+k;j<l;j+=k){
        //         summ+=energy[j];
        //         if(summ<0){
        //             if(j+k>=l) take=true;
        //             else take=false;
        //             break;
        //         }
        //     }
        //     if(take==true)
        //         maxi=max(summ,maxi);
        // }
        // return maxi;
        /////////////////////////////////////////////////////////
        // from right to left we can store value of that index and use it for right indexs
        int l=energy.size();
        for(int i=l-1;i>-1;i--){
            if(i+k<l){
                energy[i]+=energy[i+k];
            }
        }
        return *max_element(energy.begin(),energy.end());
    }
};
