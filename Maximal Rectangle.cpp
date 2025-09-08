//https://leetcode.com/problems/maximal-rectangle/description/


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> row(matrix[0].size(),0);
        int maxi=INT_MIN;
        for(vector<char> i:matrix){
            for(int j=0;j<i.size();j++){
                if(i[j]=='0'){
                    row[j]=0;
                }
                else{
                    row[j]=row[j]+1;
                }
            }
            for(int j=0;j<i.size();j++){
                //left
                int left=j;
                int right=j;
                while(left>-1){
                    if(row[left]>=row[j]){
                        left--;
                    }
                    else{
                        break;
                    }
                }
                left++;
                while(right<i.size()){
                    if(row[right]>=row[j]){
                        right++;
                    }
                    else{
                        break;
                    }
                }
                right--;
                int area=row[j]*(right-left+1);
                maxi=max(area,maxi);
            }
        }
        return maxi;
    }
};
