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




//////////////////////////////////////////////////////////////////////


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int l=matrix[0].size();
        vector<int> rectangle(l);
        vector<int> prefix(l,0);
        vector<int> suffix(l,l);
        int size=0;
        for(vector<char> row:matrix){
            stack<pair<int,int>> suffStack;
            stack<pair<int,int>> prefStack;

            for(int i=0;i<row.size();i++){
                if(row[i]=='0') rectangle[i]=0;
                else rectangle[i]++;
            }
            for(int i=0;i<l;i++){
                while(!prefStack.empty()){
                    auto t=prefStack.top();
                    if(t.first>=rectangle[i]){
                        prefStack.pop();  
                    }
                    else{
                        prefix[i]=t.second+1;
                        break;
                    }
                        
                }
                prefStack.push({rectangle[i],i});



                while(!suffStack.empty()){
                    auto t=suffStack.top();
                    if(t.first>=rectangle[l-i-1]){
                        suffStack.pop();  
                    }
                    else{
                        suffix[l-i-1]=t.second-1; 
                        break;
                    }
                       
                }
                suffStack.push({rectangle[l-i-1],l-i});
            }
            for(int i=0;i<l;i++){
                size=max(size,((suffix[i]-prefix[i])*rectangle[i]));
            }
            fill(prefix.begin(), prefix.end(), 0);
            fill(suffix.begin(), suffix.end(), l);
        }
        return size;
    }
};
