//https://leetcode.com/problems/reverse-pairs/description/


class Solution {
public:

    void mergeSort(vector<int>& nums,int low,int high,int &count){
        if(low<high){
            int mid=low+(high-low)/2;
            mergeSort(nums,low,mid,count);
            mergeSort(nums,mid+1,high,count);
            vector<int> temp;
            int i=low;
            int j=mid+1;
            //algo
            while (i<=mid && j<=high){
                
                long long x=nums[i];
                long long y=2LL*nums[j]L; //////////// 2LL -> long long 64bit  means 2 will be treated as long long with value 2
                if(x>y){
                    count=count+(mid-i+1);
                    j++;
                }
                else{
                    i++;
                }
            }



            i=low;
            j=mid+1;
            while(i<=mid && j<=high){
                if(nums[i]<nums[j]){
                    temp.push_back(nums[i]);
                    i++;
                }
                else{
                    temp.push_back(nums[j]);
                    j++;
                }
            }
            while (i<=mid){
                temp.push_back(nums[i]);
                i++;
            }

            while (j<=high){
                temp.push_back(nums[j]);
                j++;
            }

            for(int j=0;j<temp.size();j++){
                nums[low+j]=temp[j];
            }
            
        }
        return;
    }
    int reversePairs(vector<int>& nums) {
        int count=0;
        mergeSort(nums,0,nums.size()-1,count);

        return count;
    }
};
