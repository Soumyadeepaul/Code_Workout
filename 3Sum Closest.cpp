//https://leetcode.com/problems/3sum-closest/description/


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int l=nums.size();
        int summ;
        int x;
        int y;
        int minSum=NULL;
        for(int i=0;i<l-1;i++){
            summ=nums[i];
            x=i+1;
            y=l-1;
            while(x<y){
                if(minSum==NULL){minSum=summ+nums[x]+nums[y];}
                if(abs(summ+nums[x]+nums[y]-target)<abs(minSum-target)){
                   
                    minSum=summ+nums[x]+nums[y];
                    
                }
                if(summ+nums[x]+nums[y]-target<0){
                    x++;
                }
                else if(summ+nums[x]+nums[y]-target>0){
                    y--;
                }
                else{
                    return target;
                }
                
                
            }
        }
        return minSum;   
    }
};
