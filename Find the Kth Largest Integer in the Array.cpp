//https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/description/?envType=problem-list-v2&envId=quickselect


class Solution {
public:
    
    // custom comparator for numeric strings
    static bool cmp(const string &a, const string &b){
        if(a.size() != b.size())
            return a.size() > b.size();   // longer number is larger
        return a > b;                     // same length → lexicographically compare
    }

    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp); //descending order... true means no swap
        return nums[k-1];
    }
};


//TLE
// class Solution {
// public:
//     int partition(vector<string>& nums, int left, int right){
//         string pivot=nums[right];
//         int pSize=pivot.size();
//         int i=left-1;
//         for(int j=left;j<right;j++){
//             if(nums[j].size()>pSize ){}
//             else if(nums[j].size()==pSize && nums[j]>pivot){}
//             else{
//                 i++;
//                 swap(nums[i],nums[j]);
//             }
//         }
//         swap(nums[++i],nums[right]);
//         return i;
//     }
//     void select(vector<string>& nums, int k, int left, int right){
//         if(left<right){
//             int p=partition(nums,left,right);
//             if (p==k) return;
//             if(p>k) select(nums,k,left,p-1);
//             else select(nums,k,p+1,right);
//         }
//     }
//     string kthLargestNumber(vector<string>& nums, int k) {
//         k=nums.size()-k;
//         select(nums,k,0,nums.size()-1);
        
//         return nums[k];
//     }
// };
