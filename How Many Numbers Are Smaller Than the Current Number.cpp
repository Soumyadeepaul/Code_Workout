//https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/



class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int maxx=*max_element(nums.begin(),nums.end());
        cout<<maxx;
        vector<int> count(maxx+1,0);
        vector<int> count1(maxx+1,0);
        int l=nums.size();
        for(int i=0;i<l;i++){
            count[nums[i]]+=1;
        }
        for(int i=1;i<maxx+1;i++){
            count1[i]=count[i-1]+count1[i-1];
        }
        vector<int> result(l,0);
        for(int i=0;i<l;i++){
            result[i]=count1[nums[i]];
        }
        return result;
    }
};
