//https://leetcode.com/problems/boats-to-save-people/description/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int count=0;
        vector<int> taken(people.size(),0);
        for(int i=0;i<people.size();i++){
            if(taken[i]==1) continue;
            int left=limit-people[i];
            if(left==0){}
            else{
                for(int j=people.size()-1;j>i;j--){
                    if(taken[j]!=1 && people[j]<=left){
                        taken[j]=1;
                        break;
                    }
                }
            }
            count++;
        }
        return count;
    }
};
