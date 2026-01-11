//https://leetcode.com/problems/number-of-provinces/description/


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int l=isConnected.size();
        unordered_map<int,vector<int>> map;
        int nodes=isConnected[0].size();
        for(int i=0;i<l;i++){
            for(int j=0;j<nodes;j++){
                if(isConnected[i][j]==1&& i!=j){
                    map[i].push_back(j);
                }
            }
        }
        unordered_set<int> visited;
        int result=0;
        for(int i=0;i<nodes;i++){
            if(visited.count(i)) continue; //already checked

            result++;
            queue<int> q;
            q.push(i);
            visited.insert(i);

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int nei : map[node]) {
                    if (!visited.count(nei)) {
                        visited.insert(nei);
                        q.push(nei);
                    }
                }
            }
        }
        return result;
    }
};
