//https://leetcode.com/problems/jump-game-iv/description/?envType=daily-question&envId=2026-05-18


class Solution {
public:
    vector<int> visited;
    int helper(unordered_map<int,vector<int>> &map, vector<int>& arr, int idx){
        //bfs
        queue<pair<int,int>> q;
        q.push({idx,0});
        int result=INT_MAX;
        visited[idx]=1;
        int n=arr.size();
        while(!q.empty()){
            auto [x,count]=q.front();
            q.pop();
            if(x==(n-1)){
                result=count;
                break;
            }
            if(x>0 && visited[x-1]==-1){
                visited[x-1]=1;
                q.push({x-1,count+1});
            }
            if(x<(arr.size()-1) && visited[x+1]==-1){
                visited[x+1]=1;
                q.push({x+1,count+1});
            }
            for(int i:map[arr[x]]){
                if(x!=i && visited[i]==-1){
                    visited[i]=1;
                    q.push({i,count+1});
                }
            }
            map[arr[x]].clear();
        }
        return result;
    }
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>> map;
        visited.resize(arr.size(),-1);
        for(int i=0;i<arr.size();i++)
            map[arr[i]].push_back(i);
        return helper(map,arr,0);
    }
};
