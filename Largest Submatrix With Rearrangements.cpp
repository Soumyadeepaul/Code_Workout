//https://leetcode.com/problems/largest-submatrix-with-rearrangements/?envType=daily-question&envId=2026-03-17


class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int r=matrix.size(),c=matrix[0].size();
        for(int j=0;j<c;j++){
            int summ=0;
            for(int i=0;i<r;i++){
                if(matrix[i][j]!=0) matrix[i][j]=++summ;
                else summ=0;
            }
        }
        int result=0,count=0, mini=1e9;;
        for(int i=0;i<r;i++){
            count=0;
            mini=1e9;
            sort(matrix[i].begin(),matrix[i].end(), greater());
            for(int j=0;j<c;j++){
                if(matrix[i][j]!=0){
                    count++;
                    mini=min(mini,matrix[i][j]);
                    result=max(result,mini*count);
                }
                
            }
            
        }

        // for(int i=0;i<r;i++){
        //     for(int j=0;j<c;j++){
        //         cout<<matrix[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return result;
    }
};
