//https://leetcode.com/contest/weekly-contest-478/problems/minimum-absolute-distance-between-mirror-pairs/description/
//TLE  665 / 736

class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int result=INT_MAX,l=nums.size();
        
        // store the reverse
        vector<int> rev(l);
        int reverse=0,val=0;
        for(int i=0;i<l;i++){
            reverse=nums[i];
            val=0;
            while(reverse){
                val=val*10+reverse%10;
                reverse/=10;
            }
            rev[i]=val;
        }
        for(int i=0;i<l;i++){
            for(int j=i+1;j<l && result>j-i;j++){
                if(rev[i]==nums[j]) result=min(result,j-i);
            }
            if(result==1) break;
        }
        return result==INT_MAX ? -1 : result;
    }
};
