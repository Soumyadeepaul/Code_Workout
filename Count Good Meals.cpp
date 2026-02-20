//https://leetcode.com/problems/count-good-meals/description/


// class Solution {
// public:
//     int countPairs(vector<int>& deliciousness) {
//         unordered_map<int,int> map;
//         for(int i: deliciousness) map[i]++;
//         set<int> store;
//         for(int i=0;i<=20;i++){
//             store.insert(1<<i);
//         }
//         vector<vector<int>> m;
//         for(auto i:map) m.push_back({i.first,i.second});
//         int mod=1e9+7,result=0;
//         for(int i=0;i<m.size();i++){
//             for(int j=i;j<m.size();j++){
//                 if(i==j && m[i][1]>1){
//                     if(store.count(m[i][0]+m[j][0])){
//                         int n=m[i][1];
//                         result=(result+((n*(n-1))/2)%mod)%mod;
//                     }
//                 }
//                 else if(i!=j && store.count(m[i][0]+m[j][0])){

//                     result=(result+(m[i][1]*m[j][1])%mod)%mod;
//                 }
//             }

//         }
//         return result;
//     }
// };

////////////////////////////////////////////

class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int,int> map;
        for(int i: deliciousness) map[i]++;
        int mod=1e9+7,result=0;
        unordered_set<string> done;
        for(auto i:map){
            for(int j=0;j<=21;j++){
                //find
                int find=(1<<j)-i.first;
                if(find<0) continue;
                if(done.count(to_string(i.first)+to_string(find))) continue;
                if(find==i.first){
                    if(i.second>1){
                        int n=i.second;
                        result=(result+((1ll*n*(n-1))/2)%mod)%mod;
                    }
                }
                else if(map.count(find)){
                    result=(result+(1ll*i.second*map[find])%mod)%mod;
                    done.insert(to_string(i.first)+to_string(find));
                    done.insert(to_string(find)+to_string(i.first));
                }
            }


        }
        return result;
    }
};
