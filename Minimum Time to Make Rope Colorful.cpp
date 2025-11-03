//https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/?envType=daily-question&envId=2025-11-03


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int x=0;
        int y=0;
        int cost=0;
        int l=colors.size();
        colors+="!"; //end check
        while(y<l+1){
            if(colors[y]==colors[x]){
                y++;
            }
            else{
                priority_queue<int, std::vector<int>, std::greater<int>> heap(neededTime.begin()+x,neededTime.begin()+y);
                int val;
                while(!heap.empty()){
                    val=heap.top();
                    heap.pop();
                    cost+=val;
                }
                cost-=val; // 1 element should remain
                x=y;
            }
        }
        return cost;
    }
};
