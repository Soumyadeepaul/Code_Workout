//https://leetcode.com/problems/loud-and-rich/description/?envType=problem-list-v2&envId=topological-sort


class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int node=quiet.size();
        vector<int> indegree(node,0);
        unordered_map<int,vector<int>> adjList;
        for(auto edge:richer){
            indegree[edge[1]]++;
            adjList[edge[0]].push_back(edge[1]);
        }

        vector<int> result(node);
        queue<int> q;

        for(int i=0;i<node;i++){
            if(indegree[i]==0) {
                q.push(i);
            }
            result[i]=i;
        }
        while(!q.empty()){
            int top=q.front();
            q.pop();
            for(int nei:adjList[top]){
                indegree[nei]--;
                if(indegree[nei]==0){
                    q.push(nei);
                }
                if(quiet[result[nei]]>quiet[result[top]]){
                    result[nei]=result[top];
                }
            }
        }
        return result;
    }
};
