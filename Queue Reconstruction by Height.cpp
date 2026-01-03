//https://leetcode.com/problems/queue-reconstruction-by-height/description/?envType=problem-list-v2&envId=array


class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end()); //sort by height.. so that we can get some decision idea while placing
        int l=people.size();
        vector<vector<int>> result(l,vector<int>(2,-1));
        int count=0;
        for(int i=0;i<l;i++){
            count=people[i][1];
            for(int j=0;j<l;j++){
                if(count==0 && result[j][0]==-1){ //if reached to location and empty
                    result[j]=people[i];
                    break;
                }
                else{
                    if(result[j][0]>=people[i][0] || result[j][0]==-1) count--;//tracker the greater and blank space so that the element after that in loop, with is greater or equal will surly set in blank space
                }
            }
        }
        return result;
    }
};
