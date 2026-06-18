//https://leetcode.com/problems/beautiful-array/description/?envType=problem-list-v2&envId=divide-and-conquer


class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> store;
        store.push_back(1);

        while(store.size()<n){
            vector<int> temp;
            for(int i:store){
                if(2*i-1<=n){
                    temp.push_back(2*i-1);
                }
            }
            for(int i:store){
                if(2*i<=n){
                    temp.push_back(2*i);
                }
            }
            store=temp;
        }
        return store;
    }
};
