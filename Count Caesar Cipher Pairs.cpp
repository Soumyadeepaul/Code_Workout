//https://leetcode.com/problems/count-caesar-cipher-pairs/description/

class Solution {
public:
    bool helper(string a, string b){
        if(a>b) return helper(b,a);
        int gap=(b[0]-a[0])%26;
        for(int i=1;i<a.size();i++){
            int g=b[i]-a[i];
            if(g<0) g=26+g;
            if(g!=gap) return false;
        }
        return true;
    }
    vector<int> parent;
    vector<int> rank;
    vector<int> count;
    int find(int x){
        if(parent[x]!=x) parent[x]=find(parent[x]);
        return parent[x];
    }
    void uni(int x, int y){
        int px=find(x), py=find(y);
        if(px==py) return;
        if(rank[px]>rank[py]){
           parent[py]=px; 
        }
        else if(rank[px]<rank[py]){
            parent[px]=py;
        }
        else{
            parent[py]=px;
            rank[px]++;
        }
    }
    long long countPairs(vector<string>& words) {
        long long result=0;
        int l=words.size();
        parent.resize(l,0);
        rank.resize(l,0);
        count.resize(l,0);
        iota(parent.begin(), parent.end(),0);
        for(int i=0;i<words.size()-1;i++){
            for(int j=i+1;j<words.size();j++){
                if(helper(words[i],words[j])) {
                    uni(i, j);
                    break; // after this.. when jth turn will come.. it will connect
                }
            }
        }
        for(int i=0;i<parent.size();i++){
            int px=find(i);
            count[px]++;
        }
        for(int i:count) result+=(1ll*i*(i-1))/2;
        return result;
    }
};
