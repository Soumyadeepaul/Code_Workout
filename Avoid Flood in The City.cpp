//https://leetcode.com/problems/avoid-flood-in-the-city/description/?envType=daily-question&envId=2025-10-07

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        //tle
        // int l=rains.size();
        // vector<int> result(l,-1);
        // vector<int> full;
        // int j;
        // bool found=false;
        // for(int i=0;i<l;i++){
        //     if(find(full.begin(),full.end(),rains[i])!=full.end()) return {};
        //     else if(rains[i]==0){
        //         j=i;
        //         while(j<l){
        //             found=false;
        //             if(rains[j]!=0){
        //                 auto it=find(full.begin(),full.end(),rains[j]);
        //                 if(it!=full.end()){
        //                     full.erase(it);
        //                     found=true;
        //                     result[i]=rains[j];
        //                     break;
        //                 }
        //             }
        //             j++;
        //         }
        //         if (found==false)result[i]=1;
        //     }
        //     else full.push_back(rains[i]);
        // }
        // return result;

        ////////////////////////////////////////////////////////
        int l=rains.size();
        vector<int> result(l,-1);
        set<int> dryDayStore;
        unordered_map<int,int> full;
        int j;
        bool found=false;
        for(int i=0;i<l;i++){
            if(rains[i]!=0){
                int lake = rains[i];
                if (full.count(lake)) { //lake got rain before and not dry
                    // find dry day after the previous rain of this lake
                    auto it = dryDayStore.lower_bound(full[lake]); // get a dry day after the previous rain on the same lake pointing now
                    if (it == dryDayStore.end()) return {}; // flood
                    result[*it] = lake;
                    dryDayStore.erase(it);
                }
                full[lake] = i; // mark lake full today
            }
            else{
                dryDayStore.insert(i);
                result[i]=1;
                
            }
        }
        return result;
    }
};
