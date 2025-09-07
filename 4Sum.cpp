//https://leetcode.com/problems/4sum/description/


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        int l=nums.size();
        int x;
        int y;
        long long summ;
        vector<int> store;
        vector<vector<int>> check;
        for(int i=0;i<l-3;i++){
            store.push_back(nums[i]);
            for(int j=i+1;j<l-2;j++){
                store.push_back(nums[j]);
                // if(find(check.begin(),check.end(),store)!=check.end()) {
                //     store.pop_back();
                //     continue;
                // }
                check.push_back(store);
                summ=(long  long)target-(nums[i]+nums[j]);
                x=j+1;
                y=l-1;
                //two pointer summ
                while(x<y){
                    //cout<<nums[i]<<" "<<nums[j]<<" "<<nums[x]<<" "<<nums[y]<<" "<<endl;
                    if(nums[x]+nums[y]==summ){
                        store.push_back(nums[x]);
                        store.push_back(nums[y]);
                        if(find(result.begin(),result.end(),store)!=result.end()) {
                            store.pop_back();
                            store.pop_back();
                            x++;
                            y--;
                            continue;
                        }
                        result.push_back(store);
                        store.pop_back();
                        store.pop_back();
                        x++;
                        y--;
                    }
                    else if(nums[x]+nums[y]>summ){
                        //need smaller value
                        y--;
                    }
                    else{
                        //need larger value
                        x++;
                    }
                }
                store.pop_back();
            }
            store.pop_back();
        }
        return result;
    }
};
