//https://leetcode.com/problems/largest-number/?envType=problem-list-v2&envId=greedy

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> n;
        for(int i=0;i<nums.size();i++){
            n.push_back(to_string(nums[i]));
        }
        int i;
        int j;
        bool swapped;
        while(true){
            swapped=false;
            i=n.size()-2;
            j=n.size()-1;
            while(i>-1){
                if(n[i]+n[j]<n[j]+n[i]){
                    swap(n[i],n[j]);
                    swapped=true;
                }
            i--;
            j--;
            }
            if(swapped==false){
                break;
            }
        }
        
        string result;
        int zero=1;
        for(auto j:n){
            result=result+j;
            if(j!="0"){
                zero=0;
            }
        }
        if(zero==1){
            return "0";
        }
        return result;
    }
};
