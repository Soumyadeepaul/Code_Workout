//https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/description/?envType=daily-question&envId=2026-03-02


class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
       vector<int> store(grid.size(),0);
       int l=grid[0].size();
       for(int n=0;n<grid.size();n++){
            for(int i=l-1;i>-1;i--){
                if(grid[n][i]==0){
                    store[n]++;
                }
                else break;
            }
        }
        int count=0;
        for(int i=0;i<store.size();i++){
            int find=l-i-1;
            bool found=0;
            for(int j=i;j<store.size();j++){
                if(store[j]>=find){
                    found=1;
                    //swap adj and count
                    while(i!=j){
                        swap(store[j-1],store[j]);
                        count++;
                        j--;
                    }
                    break;
                }
            }
            if(found==0) return -1;
        }

        return count; 
    }
};
