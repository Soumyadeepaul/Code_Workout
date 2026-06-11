//https://www.geeksforgeeks.org/problems/the-celebrity-problem/1


class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        vector<int> popularity(n,0);
        for(auto m:mat){
            for(int j=0;j<m.size();j++){
                if(m[j]==1) popularity[j]++;
            }
        }
        queue<int> HNI;
        for(int i=0;i<n;i++){
            if(popularity[i]==n) HNI.push(i);
        }
        while(!HNI.empty()){
            int person=HNI.front();
            HNI.pop();
            int total=accumulate(mat[person].begin(),mat[person].end(),0);
            if(total==1) return person;
        }
        return -1;
    }
};
