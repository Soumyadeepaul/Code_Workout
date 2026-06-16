//https://leetcode.com/problems/min-cost-to-connect-all-points/description/?envType=problem-list-v2&envId=minimum-spanning-tree

class Solution {
public:
    int cal(int x1,int y1, int x2, int y2){
        return abs(x1-x2)+abs(y1-y2);
    }
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(parent[x]!=x) return parent[x]=find(parent[x]);
        return parent[x];
    }
    void uni(int x,int y){
        int px=find(x), py=find(y);

        if(px==py) return;

        if(rank[px]>rank[py]){
            parent[py]=parent[px];
        }
        else if(rank[px]<rank[py]){
            parent[px]=parent[py];
        }
        else{
            parent[py]=parent[px];
            rank[px]++;
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int nodes=points.size();
        if(nodes==1) return 0;
        for(int i=0;i<nodes;i++){
            for(int j=i+1;j<nodes;j++){
                pq.push({cal(points[i][0],points[i][1],points[j][0],points[j][1]),i,j});
            }
        }
        parent.resize(nodes);
        rank.resize(nodes,0);
        iota(parent.begin(),parent.end(),0);
        int result=0;
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int dis=top[0], n1=top[1], n2=top[2];
            if(find(n1)==find(n2)){}//will form cycle
            else{
                uni(n1,n2);
                result+=dis;                
            }
        }
        return result;
    }
};
