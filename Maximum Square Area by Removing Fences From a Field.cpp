//https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field/description/?envType=daily-question&envId=2026-01-16


class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());

        int mod=1e9+7;
        long long result=-1;
        hFences.insert(hFences.begin(),1);
        vFences.insert(vFences.begin(),1);
        hFences.push_back(m);
        vFences.push_back(n);
        int l1=hFences.size(),l2=vFences.size();
        unordered_set<int> hStore,vStore;
        // get all possible sizes from each fence to its previous fence present and removed
        for(int i=0;i<l1;i++){
            for(int j=0;j<i;j++){
                hStore.insert(hFences[i]-hFences[j]);
            }
        }
        for(int i=0;i<l2;i++){
            for(int j=0;j<i;j++){
                vStore.insert(vFences[i]-vFences[j]);
            }
        }

        vector<int> h(hStore.begin(),hStore.end());
        for(int i=0;i<h.size();i++){
            if(vStore.find(h[i])!=vStore.end()){
                result=max(result,h[i]*1LL*h[i]);
            }
        }

        return result%mod;
    }
};
