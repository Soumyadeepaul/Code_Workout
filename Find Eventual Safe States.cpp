//https://leetcode.com/problems/find-eventual-safe-states/description/



class Solution {
public:
    vector<int> state;
    int helper(vector<vector<int>>& graph, int idx){
        
        if(state[idx]!=0) { //if it is already visited
            return state[idx]==2; // check if attained safe state or not   (else it is visited before and loop found)
        }
        state[idx]=1; //consider visited
        for(int nei:graph[idx]){
            if(!helper(graph,nei)) return false; //if loop
        }
        state[idx]=2; //if no loop
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        state.resize(graph.size(),0);
        vector<int> result;
        for(int i=0;i<graph.size();i++){
            if(helper(graph,i)) result.push_back(i);
        }
        return result;
    }
};
