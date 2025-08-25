//https://leetcode.com/problems/next-permutation/description/


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot=nums.size()-1;
        int sorted=1;
        for(;pivot>0;pivot--){
            if (nums[pivot]>nums[pivot-1]){
                pivot=pivot-1;
                sorted=0;
                break;
            }
        }
        //cout<<pivot;
        if (pivot==0 && sorted==1){
            //reverse
            int end=nums.size()-1;
            while (pivot<end){
                swap(nums[pivot],nums[end]);
                pivot++;
                end--;
            }
        }
        else{
            //find next minimum
            int minimum=nums[pivot+1];
            int index=pivot+1;
            for(int i=pivot+1;i<nums.size();i++){
                if(minimum>=nums[i] and nums[i]>nums[pivot]){ // always greater then pivot and if multiple same value occure in right side... consider the least significate possible to swap... so that while reversing the right side... minimum(pivot) element comes before than larger
                    minimum=nums[i];
                    index=i;
                }
            }
            swap(nums[index],nums[pivot]);
            //reverse
            int end=nums.size()-1;
            while (pivot+1<end){
                //cout<<pivot+1<<" "<<end;
                swap(nums[pivot+1],nums[end]);
                pivot++;
                end--;
            }
            
        }

    }
};
