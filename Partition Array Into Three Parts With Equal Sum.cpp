//https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/description/


class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int s=accumulate(arr.begin(),arr.end(),0);
        if(s%3!=0) return false;
        int equal=s/3;
        int l=arr.size();
        int summ=0;
        int count=0;
        for(int i=0;i<l;i++){
            summ+=arr[i];
            
            if(summ==equal){
                count++;
            }
            if(summ==equal && count==3){
                return true;
            }
            if(summ==equal){
                summ=0;
            }
        }
        return false;
    }
};
