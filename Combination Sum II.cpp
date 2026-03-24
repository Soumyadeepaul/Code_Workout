//https://leetcode.com/problems/combination-sum-ii/description/


class Solution {
public:
    void combination(vector<int>& candidates, int target,int index,vector<vector<int>> &result,vector<int> stack,int &size){
        if(target==0){
            result.push_back(stack);
            return;
        }
        if(index==size){
            return;
        }
        for(int i=index;i<size;i++){
            if(i>index && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) continue;
            stack.push_back(candidates[i]);
            combination(candidates,target-candidates[i],i+1,result,stack,size);
            stack.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //we have to keep track of duplicate element in result list
        vector<vector<int>> result;
        sort(candidates.begin(),candidates.end());
        vector<int>stack;
        int size=candidates.size();
        combination(candidates,target,0,result,stack,size);
        return result;
    }
};
