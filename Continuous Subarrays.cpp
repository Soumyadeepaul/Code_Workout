//https://leetcode.com/problems/continuous-subarrays/description/?envType=problem-list-v2&envId=queue


class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long result=0;
        int i=0,j=0,l=nums.size();
        long long maxi=nums[0],mini=nums[0];
        while(j<l){
            //keep track of max min in slinging window
            maxi=(maxi<nums[j])? nums[j]:maxi;
            mini=(mini>nums[j])? nums[j]:mini;
            
            if(abs(maxi-mini)<=2 && abs(maxi-mini)>=0){}
            else{
                //if condition breaks   find until u get proper max min
                while(!(abs(maxi-mini)<=2 && abs(maxi-mini)>=0) && i<j){
                    if(nums[i]==maxi){
                        maxi=*max_element(nums.begin()+i+1,nums.begin()+j+1);
                    }
                    else if(nums[i]==mini){
                        mini=*min_element(nums.begin()+i+1,nums.begin()+j+1);
                    }
                    i++;
                }
                
            }
            //perform count by... new cal - cal that could happen with 1 lesser index
            //[5,4]...
            // [5] = 1
            // [5][4][5,4] =3
            // but [5] was already counted... there for 1+(3-1)=3
            int n=j-i+1;
            result+=((n*1LL*(n+1))/2)-(((n-1)*1LL*(n))/2);
            j++;
            

        }
        return result;
    }
};
