//https://leetcode.com/problems/number-of-visible-people-in-a-queue/description/?envType=problem-list-v2&envId=interview-instance-iii



//TLE
// class Solution {
// public:
//     vector<int> canSeePersonsCount(vector<int>& heights) {
//         int h=heights.size();
//         vector<int> result(h,0);
//         for(int i=h-1;i>-1;i--){
//             int count=0,maxi=0;
//             for(int j=i+1;j<h;j++){
//                 if(maxi<heights[j] && maxi<heights[i]) count++;
//                 if(heights[j]>maxi){
//                     maxi=heights[j];
//                 }
//                 if(maxi>heights[i]){
//                     index[i]=j;
//                     break;
//                 }
//             }
//             result[i]=count;
//         }
//         return result;
//     }
// };

/////////////////////////////////
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int h=heights.size();
        vector<int> result(h,0);
        stack<pair<int,int>> s;
        for(int i=0;i<h;i++){
            // monotonic increasing 
            while(!s.empty() && s.top().first<heights[i]){
                auto p=s.top();
                result[p.second]++;
                s.pop();
            }
            // previous taller can see then new taller
            if(!s.empty()) result[s.top().second]++;
            s.push({heights[i],i});
        }
        return result;
    }
};
