//

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int l=nums.size();
        vector<int> result(l,-1);
        stack<int> bucket;
        for(int i=l-1;i>-1;i--){
            if(i==l-1){
                for(int j=l-1;j>-1;j--){// for last element... traverse once in reverse order... [2,5,4,7,2,1] for such case...
                    if(nums[j]>nums[i]){
                        bucket.push(nums[j]);
                        result[i]=nums[j];
                    }
                }
                bucket.push(nums[i]);
            }
            else{
                while(!bucket.empty()){
                    int t=bucket.top();
                    if(t<=nums[i]){
                        bucket.pop();
                    }
                    else{
                        result[i]=t;
                        break;
                    }
                }
                bucket.push(nums[i]);
            }
        }
        return result;
    }
};
