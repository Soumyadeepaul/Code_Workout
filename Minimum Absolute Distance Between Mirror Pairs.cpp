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


/////////////////////////////////////////////////////////
//SOLVED



class Solution {
public:
    int helper(int n){
        
        string s=to_string(n);
        int l=s.size()-1;
        while(s[l]=='0'){
            s.erase(l);
            l--;
        }
        reverse(s.begin(),s.end());
        int newN=stoi(s);
        return newN;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]].emplace_back(i);
        }
        int result=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int rev=helper(nums[i]);
            vector<int> &idx=map[rev];
            if(idx.size()==0) continue;
            auto add=upper_bound(idx.begin(),idx.end(),i);
            if(add==idx.end()) continue;
            result=min(result,abs(i-*add));
        }
        return (result==INT_MAX)? -1:result;
    }
};
