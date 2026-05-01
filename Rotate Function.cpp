//https://leetcode.com/problems/rotate-function/description/?envType=daily-question&envId=2026-05-01



class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int result=0;
        int length=nums.size();
        vector<int> prefixSum(length);
        vector<int> suffixSum(length);
        int add=0, addS=0;
        for(int i=0;i<length;i++) {
            result+=nums[i]*i;
            add+=nums[i];
            prefixSum[i]=add;
            addS+=nums[length-1-i];
            suffixSum[i]=addS;
        }
        int loop=length-1;
        int idx=length-1;
        int val=result;
        int suffixIdx=0;
        while(loop!=0){
            int toSub=(length-1)*nums[idx--];
            val-=toSub;
            int toAdd1=prefixSum[idx];
            val+=toAdd1;
            int toAdd2=0;
            if(loop<=length-2){
                toAdd2=suffixSum[suffixIdx++];
                val+=toAdd2;
            }
            result=max(result,val);
            loop--;
        }

        return result;
    }
};
