//https://leetcode.com/problems/minimum-height-trees/description/?envType=problem-list-v2&envId=graph


class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0}; 
        vector<int> degree(n,0);
        vector<vector<int>> adjList(n);
        for(auto e:edges){
            degree[e[0]]++;
            degree[e[1]]++;
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        int nodesRemaining=n;
        queue<int> degreeOne;
        for(auto i=0;i<n;i++){
            if(degree[i]==1) degreeOne.push(i);
        }
        if(degreeOne.size()<=2 && nodesRemaining<=2){
            vector<int> result;
            while(!degreeOne.empty()){
                result.push_back(degreeOne.front());
                degreeOne.pop();
            }
            return result;
        } 
        queue<int> nextLeaf;
        queue<int> empty;
        while(!degreeOne.empty()){
            int node=degreeOne.front();
            degreeOne.pop();
            nodesRemaining--;
            for(auto nei:adjList[node]){
                degree[nei]--;
                if(degree[nei]==1){
                    nextLeaf.push(nei);
                }
            }
            if(degreeOne.size()==0){
                if(nextLeaf.size()==2 && nodesRemaining==2) break;
                else if(nextLeaf.size()==1 && nodesRemaining==1) break;
                else{
                    degreeOne=nextLeaf;
                    nextLeaf=empty;
                }
            }
        }
        vector<int> result;
        while(!nextLeaf.empty()){
            result.push_back(nextLeaf.front());
            nextLeaf.pop();
        }
        return result;
    }
};
