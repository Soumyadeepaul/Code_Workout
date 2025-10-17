//https://leetcode.com/problems/destroy-sequential-targets/description/



class Solution {
public:
    
    // int destroyTargets(vector<int>& nums, int space) {
    //     sort(nums.begin(),nums.end());
    //     int result=0;
    //     int canDistroy=0;
    //     int maxDistroy=0;
    //     int l=nums.size();
    //     int j,k;
    //     vector<bool> distroyed(l,false);
    //     for(int i=0;i<l;i++){
    //         if(distroyed[i]==true) continue;
    //         j=i;
    //         k=0;
    //         canDistroy=0;
    //         for(;j<l;j++){
    //             if((nums[j] - nums[i]) % space == 0){
    //                 canDistroy++;
    //                 distroyed[j]=true;
    //             }
    //         }
    //         if(maxDistroy<canDistroy){
    //             maxDistroy=canDistroy;
    //             result=nums[i];
    //         }
            
    //     }
    //     return result;
    // }



    // x + a*y = val
    // means val%x==(0*space or c*0) means divisible




    int destroyTargets(vector<int>& nums, int space) {
        int l=nums.size();
        unordered_map<int,int> freq; 
        int result=INT_MAX;
        int maxi=0;
        int x;
        for(int i=0;i<l;i++){
            x=nums[i]%space;
            freq[x]++;
            maxi = max(maxi, freq[x % space]);
        }
        for(int i=0;i<l;i++){
            if (freq[nums[i] % space] == maxi)
            {
                result=min(result,nums[i]);
            }
        }
        return result;

    }
};

