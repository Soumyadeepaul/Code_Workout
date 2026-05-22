//https://leetcode.com/problems/task-scheduler/description/


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>map;
        for(char ch:tasks) map[ch]++;

        priority_queue<pair<int,int>> pq;
        unordered_map<char, int> tracker;
        for(auto p:map){
            pq.push({p.second,p.first});
            tracker[p.first]=0;
        }

        
        

        int curr=0;
        int placed=0;
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            map[top.second]--;
            tracker[top.second]=n+1;
            curr++;
            placed++;
            if(placed==tasks.size()) break;
            else{
                for(auto p:tracker){
                    tracker[p.first]--;
                    if(tracker[p.first]==0){
                        if(map[p.first]!=0) pq.push({map[p.first],p.first});
                    }
                }
                if(pq.size()==0){
                    while(pq.size()==0){
                        curr++;
                        for(auto p:tracker){
                            tracker[p.first]--;
                            if(tracker[p.first]==0){
                                if(map[p.first]!=0) pq.push({map[p.first],p.first});
                            }
                        }
                    }
                }
            }
            
        }
        return curr;
    }
};
