//https://leetcode.com/problems/longest-consecutive-sequence/



class Solution {
public:
    int result=0;
    unordered_map<int,int> map; 
    int find(int x){
        if(!map.count(x)) return x+1;
        else if(map[x]==-1) map[x]=find(x-1);
        return map[x]; 
    }
    void uni(int x, int y){
        if(map.count(y) && map[y]!=-1) {
            map[x]=map[y];
            result=max(result,x-map[x]);
            return;
        }
        // if(!map.count(y)) map[x]=x;
        else{
            int f=find(y);
            map[x]=f;
            result=max(result,x-map[x]);
        }

    }
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        for(int i=0;i<nums.size();i++) map[nums[i]]=-1;

        for(int i:nums)
            uni(i,i-1);
        // for(auto p:map){
        //     cout<<p.first<<" "<<p.second<<endl;
        // }
        return result+1;
    }
};
