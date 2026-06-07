//https://leetcode.com/problems/accounts-merge/description/


class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(parent[x]!=x) parent[x]=find(parent[x]);
        return parent[x];
    }

    void uni(vector<string> &a, vector<string> &b, int i, int j){
        int pa,pb;
        bool same=false;
        for(int s1=1;s1<a.size();s1++){
            for(int s2=1;s2<b.size();s2++){
                if(a[s1]==b[s2]){
                  pa=find(i);
                  pb=find(j);  
                  same=true;
                  break;
                }
            }
        }
        if(pa==pb) return;

        if(same==true){
            if(rank[pa]>rank[pb]){
                parent[pb]=parent[pa];
            }
            else if(rank[pa]<rank[pb]){
                parent[pa]=parent[pb];
            }
            else{
                parent[pb]=pa;
                rank[pa]++;
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        parent.resize(accounts.size());
        rank.resize(accounts.size(),0);
        iota(parent.begin(),parent.end(),0);
        for(int i=0;i<accounts.size();i++){
            for(int j=i+1;j<accounts.size();j++){
                if(accounts[i][0]==accounts[j][0]){
                    uni(accounts[i],accounts[j],i,j);
                }
            }
        }

        unordered_map<int,set<string>> map; //index based

        for(int i=0;i<parent.size();i++){
            int parent=find(i);
            for(int j=1;j<accounts[i].size();j++){
                map[parent].insert(accounts[i][j]);
            }
        }
        vector<vector<string>> result;
        for(auto &p:map){
            vector<string> store;
            store.push_back(accounts[p.first][0]);
            for(auto it=p.second.begin();it!=p.second.end();it++) store.push_back(*it);

            result.push_back(store);
        }
        return result;
    }
};
