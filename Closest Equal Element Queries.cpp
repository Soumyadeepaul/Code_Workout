//https://leetcode.com/problems/closest-equal-element-queries/?envType=daily-question&envId=2026-04-16


class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>> map;
        int l=nums.size();
        for(int i=0;i<l;i++){
            map[nums[i]].emplace_back(i);
        }
        vector<int> result(queries.size(),-1);
        for(int i=0;i<queries.size();i++){
            int element=nums[queries[i]];
            vector<int> &indexs=map[element];
            if(indexs.size()==1) continue;
            int value=1e9+7;
            int pos=lower_bound(indexs.begin(),indexs.end(),queries[i])-indexs.begin();
            int left=indexs[(pos-1+indexs.size())%indexs.size()];
            int d1=abs(queries[i]-left);
            value=min(value,min(d1,l-d1));

            int right=indexs[(pos+1)%indexs.size()];
            int d2=abs(queries[i]-right);
            value=min(value,min(d2,l-d2));
            result[i]=value;
            
        }   
        return result;

    }
};
