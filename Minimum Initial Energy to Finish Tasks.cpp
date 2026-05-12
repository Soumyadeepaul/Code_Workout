//https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/description/?envType=daily-question&envId=2026-05-12


class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[](const auto &a, const auto &b){
            return (a[1]-a[0])>(b[1]-b[0]);
        });
        int result=INT_MAX;
        long long start=1, end=pow(10,9);

        while(start<=end){
            long long mid=(start+end)/2;
            long long temp=mid;
            int found=1;
            for(auto &i:tasks){
                if(temp>=i[1]) temp-=i[0];
                else {
                    found=0;
                    break;
                }
            }
            if(found==1){
               
                result=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return result;
    }
};
