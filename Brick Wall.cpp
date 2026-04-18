//https://leetcode.com/problems/brick-wall/description/


class Solution {
public:
    // int helper(long long mid,vector<vector<int>>& wall){
    //     int count=0;
    //     for(vector<int> w:wall){
    //         auto pos=lower_bound(w.begin(),w.end(),mid);
    //         if(pos==w.end()) continue;
    //         if(*pos>mid) count++;
    //     }
    //     return count;

    // }
    // int leastBricks(vector<vector<int>>& wall) {
        
    //     for(int i=0;i<wall.size();i++){
    //         for(int j=1;j<wall[i].size();j++){
    //             wall[i][j]+=wall[i][j-1];
    //         }
    //     }
    //     long long maximum=wall[0][wall[0].size()-1];
    //     long long minimum=1, mid;
    //     int result=INT_MAX;
    //     while(maximum--!=0){
    //         // mid=(maximum+minimum)/2;
    //         mid=maximum;
    //         int count=helper(mid,wall);
    //         // cout<<mid<<" "<<count<<endl;
    //         if(count<result){
    //             // maximum=mid-1;
    //             result=count;
                
    //         }
    //         // else minimum=mid+1;
    //     }

    //     return result;

    // }


    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long,int> count;
        for(int i=0;i<wall.size();i++){
            if(wall[i].size()==1) continue;
            long long summ=0;
            for(int j=0;j<wall[i].size()-1;j++){
                summ+=wall[i][j];
                count[summ]++;
            }
        }
        int result=0;
        for(auto p:count){
            result=max(result,p.second); //maximize gap count
        }
        return wall.size()-result;

    }
};
