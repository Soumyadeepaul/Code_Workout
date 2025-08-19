//https://leetcode.com/problems/majority-element-ii/description/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> hashmap;
        vector<int> result;
        int l=0;
        for(int i=0;i<nums.size();i++){
            if(hashmap.find(nums[i])!=hashmap.end()){
                hashmap[nums[i]]=hashmap[nums[i]]+1;
                if(hashmap[nums[i]]>floor(nums.size()/3)){
                    if(find(result.begin(),result.end(),nums[i])==result.end()){
                        result.push_back(nums[i]);
                    }
                }
            }
            else{
                if (l==3){
                    vector<int> remove;
                    for( auto& pair:hashmap){
                        hashmap[pair.first]=pair.second-1;
                        if(hashmap[pair.first]==0){
                            remove.push_back(pair.first);
                            
                        }
                    }
                    for(int r=0;r<remove.size();r++){
                        hashmap.erase(remove[r]);
                        l--;
                    }
                }
                if(l<3){
                    hashmap.insert({nums[i],1});
                    l++;
                }
            }
        }
        for( auto pair:hashmap){
            //traverse and check the count of the element in nums left out in hashmap
            int count=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]==pair.first){
                    count++;
                }
                if(count>floor(nums.size()/3)){
                    if(find(result.begin(),result.end(),nums[i])==result.end()){
                        result.push_back(nums[i]);
                    }
                    break;
                }
            }
        }
        return result;
    }
};
