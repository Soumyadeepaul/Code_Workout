//https://leetcode.com/problems/combination-sum/description/


class Solution {
public:
    void combination(vector<int>& candidates,int target,int index,vector<int> takeOrNotTake,vector<vector<int>> &result){
        int summ=accumulate(takeOrNotTake.begin(),takeOrNotTake.end(),0);
        if(summ>target || index==candidates.size()){
            return;
        }
        else if(summ==target){
            result.push_back(takeOrNotTake);
            return;
        }
        else{
            takeOrNotTake.push_back(candidates[index]);
            combination(candidates,target,index,takeOrNotTake,result);//take it repetively
            takeOrNotTake.pop_back();
            combination(candidates,target,index+1,takeOrNotTake,result);

        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> takeOrNotTake;
        combination(candidates,target,0,takeOrNotTake,result);
        return result;
    }
};
