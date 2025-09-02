//https://leetcode.com/problems/next-greater-element-i/description/



class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nGeNums2;
        stack<int> bucket;
        for(int j=nums2.size()-1;j>-1;j--){
            if(bucket.empty()) {
                nGeNums2.push_back(-1);
                bucket.push(nums2[j]);
            }
            else{
                if(nums2[j]>bucket.top()){
                    while(!bucket.empty()){
                        if(nums2[j]>bucket.top()){
                            bucket.pop();
                        }
                        else{
                            break;
                        }
                    }
                    if(bucket.empty()){
                        nGeNums2.push_back(-1);
                        bucket.push(nums2[j]);
                    }
                    else{
                        nGeNums2.push_back(bucket.top());
                        bucket.push(nums2[j]);
                    }
                }
                else{
                    nGeNums2.push_back(bucket.top());
                    bucket.push(nums2[j]);
                }
            }
        }

        unordered_map<int,int> map;
        int size=nGeNums2.size()-1;
        for(int i=0;i<nums2.size();i++){
            map[nums2[i]]=nGeNums2[size-i];
        }
        vector<int> result;
        for(int i:nums1){
            result.push_back(map[i]);
        }
        return result;
    }
};
