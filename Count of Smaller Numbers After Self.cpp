//https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/


class Solution {
public:
    void function(vector<pair<int,int>> &nums,int left,int right,vector<int> &result){
        if(left<right){
            int mid=left+(right-left)/2;
            function(nums,left,mid,result);
            function(nums,mid+1,right,result);
            vector<pair<int,int>> leftArr(nums.begin()+left,nums.begin()+mid+1);
            vector<pair<int,int>> rightArr(nums.begin()+mid+1,nums.begin()+right+1);
            int i;
            int j;
            i=0;
            j=0;
            int k=left;
            while(i<leftArr.size()&&j<rightArr.size()){
                if(leftArr[i].first>rightArr[j].first){
                    result[leftArr[i].second]+=rightArr.size()-j;
                    nums[k]=leftArr[i];
                    i++;
                }
                else{
                    nums[k]=rightArr[j];
                    j++;
                }
                k++;
            }
            while(i<leftArr.size()){
                nums[k]=leftArr[i];
                i++;
                k++;
            }
            while(j<rightArr.size()){
                nums[k]=rightArr[j];
                j++;
                k++;
            }
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int l=nums.size();
        vector<int> result(l,0);
        vector<pair<int,int>> numIndex(l);
        for (int i = 0; i < l; i++) numIndex[i] = {nums[i], i};
        function(numIndex,0,l-1,result);
        return result;
    }
};
