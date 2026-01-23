//https://leetcode.com/problems/minimum-pair-removal-to-sort-array-ii/description/?envType=daily-question&envId=2026-01-23


class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        vector<long long> temp;
        set<pair<long long,int>> store;
        int badPairs=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                badPairs++;
            }
            store.insert({nums[i]+nums[i+1],i});
            temp.push_back(nums[i]);
        }
        temp.push_back(nums[nums.size()-1]);

        vector<int> nextIdx(nums.size());
        vector<int> prevIdx(nums.size());
        for(int i=0;i<nums.size();i++){
            nextIdx[i]=i+1;
            prevIdx[i]=i-1;
        }

        int result=0;
        while (badPairs>0){
            int first= store.begin()->second; //index
            int second=nextIdx[first];//adindex
            // the elements that getting added... fl and sr is the adj element of it
            int first_left=prevIdx[first];
            int second_right=nextIdx[second];

            store.erase(begin(store));

            if(temp[first]>temp[second]){
                badPairs--;
            }

            //{d,(a,b)}
            //prev bad now good
            if(first_left>=0){
                if(temp[first_left]>temp[first] &&
                    temp[first_left]<=temp[first]+temp[second]){
                        badPairs--;
                }
                //prev good now bad
                else if(temp[first_left]<=temp[first] &&
                    temp[first_left]>temp[first]+temp[second]){
                        badPairs++;
                }
            }

            //{(a,b),d}
            //prev good now bad
            if(second_right<nums.size()){
                if(temp[second_right]>=temp[second] &&
                    temp[second_right]<temp[first]+temp[second]){
                        badPairs++;
                }
                //prev bad now good
                else if(temp[second_right]<temp[second] &&
                    temp[second_right]>=temp[first]+temp[second]){
                        badPairs--;
                }
            }

            if(first_left>=0){
                store.erase({temp[first_left]+temp[first],first_left});
                store.insert({temp[first_left]+temp[first]+temp[second],first_left});
            }
            if(second_right<nums.size()){
                store.erase({temp[second_right]+temp[second],second});
                store.insert({temp[second_right]+temp[first]+temp[second],first});
                prevIdx[second_right]=first;
            }

            nextIdx[first]=second_right;
            temp[first]+=temp[second];
            result++;
        }

        return result;
    }
    
};
