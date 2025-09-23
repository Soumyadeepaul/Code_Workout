//https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
//TLE 


class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        vector<int> result;
        vector<vector<int>> profit1;
        vector<int> create;
        int maxx=INT_MIN;
        int l=deadline.size();
        for(int i=0;i<l;i++){
            create.push_back(profit[i]);
            create.push_back(deadline[i]);
            maxx=max(maxx,deadline[i]);
            profit1.push_back(create);
            create.clear();
        }
        vector<int> schedule(maxx+1,0);
        
        sort(profit1.begin(),profit1.end(),[](vector<int>&a,vector<int>&b){return a[0]>b[0];});
        int d,p;
        int count=0;
        int profitMax=0;
        int filledTill=0;
        for(int i=0;i<l;i++){
            d=profit1[i][1];
            p=profit1[i][0];
            while(d>filledTill && filledTill!=maxx+1){
                if(schedule[d]==0){
                    schedule[d]=p;
                    count++;
                    profitMax+=p;
                    while (schedule[filledTill+1]!=0) filledTill++;
                    break;
                }
                d--;
            }
        }
        result.push_back(count);
        result.push_back(profitMax);
        return result;
        
    }
};
