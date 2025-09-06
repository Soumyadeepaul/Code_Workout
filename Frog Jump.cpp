//https://leetcode.com/problems/frog-jump/description/


class Solution {
public:
    bool canCross(vector<int>& stones) {
        //////////////////////////////////////////////////////////////
        /*
        looping forward (i)
        for each i we r looking back from i-1
        we r maintaining a dp... where steps r stored which is s[i]-s[j]
        ans we store all possible differences.. only when k-1<=s[i]-s[j]<=k+1
        if i cant satisfy the condition... just store [0]

        if dp at j... stores 0 except j==0..... we shouldnt check for it becoz 0+1 will also become valid step.
        */
        /////////////////////////////////////////////////////////////
        int atIndex=0;
        int l=stones.size();
        vector<vector<int>> dpMaxSet;
        vector<int> step={0};
        dpMaxSet.push_back(step);
        int j;//for looking back
        int inserted;
        for(int i=1;i<l;i++){
            j=i-1;
            inserted=0;
            while (j>-1){
                for(int step:dpMaxSet[j]){
                    if(step==0 && j!=0){
                        //do nothing
                    }
                    else if(stones[i]-stones[j]>step+1 || stones[i]-stones[j]<step-1){
                        //do nothing
                        // we r not breaking it becoz... there may be some jth index might need bigger jump... but it all depends on the steps stored in dp at jth...
                    }
                    else{
                        inserted=1;
                        if(i>dpMaxSet.size()-1){
                            vector<int> enter={stones[i]-stones[j]};
                            dpMaxSet.push_back(enter);
                        }
                        else{
                            dpMaxSet[i].push_back(stones[i]-stones[j]);
                        }
                        
                        break;
                    }
                }
                j--;
            }
            if(inserted==0){
                dpMaxSet.push_back(step);
            }
        }
        // for(vector<int> i:dpMaxSet){
        //     for (int j:i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        if(dpMaxSet[l-1][0]==0)return false;
        return true;
    }
};
