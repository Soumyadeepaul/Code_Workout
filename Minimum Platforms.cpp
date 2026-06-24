//https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1


// class Solution {
//   public:
//     int minPlatform(vector<int>& arr, vector<int>& dep) {
//         // code here
//         vector<vector<int>> interval;
//         for(int i=0;i<arr.size();i++) interval.push_back({arr[i],dep[i]});
//         sort(interval.begin(),interval.end());
//         int result=1;
//         stack<int> end; //store smaller endings
//         for(int i=0;i<interval.size();i++){
//             while(!end.empty() && end.top()<interval[i][0]){
//                 end.pop();
//             }
//             //monotonic... smaller above
//             stack<int> smaller;
//             while(!end.empty() && end.top()<interval[i][1]){
//                 smaller.push(end.top());
//                 end.pop();
//             }
//             end.push(interval[i][1]);
//             while(!smaller.empty()){
//                 end.push(smaller.top());
//                 smaller.pop();
//             }
//             int size=end.size();
//             result=max(result,size);
//         }
//         return result;
//     }
// };

class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        vector<vector<int>> interval;
        for(int i=0;i<arr.size();i++) interval.push_back({arr[i],dep[i]});
        sort(interval.begin(),interval.end());
        int result=1;
        priority_queue<int,vector<int>,greater<int>> end;
        int count=0;
        for(int i=0;i<interval.size();i++){
            while(!end.empty() && end.top()<interval[i][0]){
                end.pop();
                count--;
            }
            end.push(interval[i][1]);
            count++;
            result=max(result,count);
        }
        return result;
    }
};




