//https://leetcode.com/contest/weekly-contest-478/problems/count-elements-with-at-least-k-greater-values/description/


class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int count=0;
        unordered_map<int,int> map;
        unordered_set<int> unique;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
            unique.insert(nums[i]);
        }
        vector<int> uni(unique.begin(),unique.end());
        sort(uni.begin(),uni.end());
        int l=uni.size();
        long long summ=0;
        for(int i=l-1;i>-1;i--){ //start from end
            if(k==0 || summ>=k){
                count+=map[uni[i]];
                continue;
            }
            else{
                summ=(long long) summ+map[uni[i]];
            }
            
        }
        return count;
    }
};
