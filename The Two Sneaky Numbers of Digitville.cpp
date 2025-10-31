//https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/description/?envType=daily-question&envId=2025-10-31


class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int> map;
        int x=-1,y=-1;
        for(int i : nums){
            map[i]++;
            if(map[i]==2 && x==-1) x=i;
            else if(map[i]==2 && x!=-1){
                y=i;
                break;
            }
        }
        return {x,y};
    }
};
