//https://leetcode.com/problems/longest-cycle-in-a-graph/description/
//TLE
class Solution {
public:
    int longestCycle(vector<int>& edges) {
        vector<int> cycle(edges.size(),-1);
        //dfs
        int result=0;
        for(int i=0;i<edges.size();i++){
            if(cycle[i]!=-1) continue;
            stack<pair<int,int>> s;
            s.push({i,0});
            vector<int> visited(edges.size(),0);
            while(!s.empty()){
                auto p=s.top();
                s.pop();
                // cout<<p.first<<" "<<p.second<<endl;
                if(visited[p.first]!=0){
                    cycle[i]=p.second-visited[p.first];
                    result=max(result,cycle[i]);
                    break;
                }
                if(edges[p.first]==-1) continue;
                s.push({edges[p.first],p.second+1});
                visited[p.first]=p.second;
            }
        }
        return (result==0)? -1:result;
    }
};

//////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();

        vector<int> cycle(n, -1);     // stores the distance (depth) of node in current traversal
        vector<int> visited(n, 0);    // stores which traversal visited the node
        int result = -1;              // longest cycle length

        for(int i = 0; i < n; i++){

            // if node already processed, skip
            if(cycle[i] != -1) continue;

            stack<pair<int,int>> s;
            s.push({i,0});  // {node, distance from start}

            while(!s.empty()){

                auto [node, dist] = s.top();
                s.pop();

                // if node already visited in this same traversal -> cycle found
                if(visited[node] == i+1){
                    result = max(result, dist - cycle[node]);
                    break;
                }

                // if visited in some previous traversal -> no cycle possible from here
                if(visited[node] != 0) break;

                // if node has no outgoing edge
                if(edges[node] == -1) break;

                // mark node visited in current traversal
                // mark node as visited in the current traversal (i+1 used so 0 still means unvisited)
                // if it would be 0 for 0.. will cause prb
                visited[node] = i+1;

                // store distance of this node from starting node
                cycle[node] = dist;

                // move to next node
                s.push({edges[node], dist+1});
            }
        }

        return result;
    }
};
