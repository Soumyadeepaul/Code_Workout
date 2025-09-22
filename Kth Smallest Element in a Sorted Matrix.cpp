//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int minn=matrix[0][0];
        int l=matrix.size()-1;
        int maxx=matrix[l][l];
        int mid;
        int count;
        while(minn<maxx){
            mid=minn+(maxx-minn)/2;
            count=0;
            for(int i=0;i<=l;i++){
                
                count+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
                
            }
            if(count>=k){
                maxx=mid;
            }
            else{
                minn=mid+1;
            }
        }
        return minn;
    }
};
