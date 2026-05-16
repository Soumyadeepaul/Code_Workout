//https://www.geeksforgeeks.org/problems/topological-sort/1


class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int,vector<int>> dependence;
        vector<int> inDegree(V,0);
        for(auto e:edges){
            dependence[e[0]].push_back(e[1]);
            inDegree[e[1]]++;
        }
        queue<int> noIndegree;
        for(int i=0;i<V;i++){
            if(inDegree[i]==0) noIndegree.push(i);
        }
        vector<int> result;
        while(!noIndegree.empty()){
            vector<int> &temp=dependence[noIndegree.front()];
            result.push_back(noIndegree.front());
            noIndegree.pop();
            for(int i:temp){
                inDegree[i]--;
                if(inDegree[i]==0) noIndegree.push(i);
            }
        }
        return result;
        
    }
};
