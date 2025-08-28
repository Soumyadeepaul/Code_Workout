//https://leetcode.com/problems/course-schedule/


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //if cycle found... result is False
        
        vector<int> loopNotFoundCheckAlready;
        unordered_map<int,vector<int>> hashmap;
        for(int i=0;i<prerequisites.size();i++){
            hashmap[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        // for(auto &i:hashmap){
        //     cout<<i.first<<" ";
        //     for(auto j: i.second){
        //         cout<<j<<" ";
        //     }
        //     cout<<"\n";
        // }

        stack<int> bucket;
        for(int i=0;i<numCourses;i++){
            bucket.push(i);
            int search;
            vector<int> visited;
            while(!bucket.empty()){
                search=bucket.top();
                visited.push_back(search);
                int toEnter;
                if(find(loopNotFoundCheckAlready.begin(),loopNotFoundCheckAlready.end(),search)==loopNotFoundCheckAlready.end()){// not yet checked before for loop
                    if(hashmap[search].empty()){
                        loopNotFoundCheckAlready.push_back(search);
                        bucket.pop();
                    }
                    while(!hashmap[search].empty()){
                        toEnter=hashmap[search][hashmap[search].size()-1];
                        if(find(loopNotFoundCheckAlready.begin(),loopNotFoundCheckAlready.end(),toEnter)==loopNotFoundCheckAlready.end()){
                            if(find(visited.begin(),visited.end(),toEnter)!=visited.end()){
                                return false;
                            }
                        }
                        bucket.push(toEnter);
                        hashmap[search].pop_back();
                    }
                    
                }

                else{
                    bucket.pop();
                }



            }
        }
        
        return true;
    }
};
