//https://leetcode.com/problems/course-schedule-ii/description/


class Solution {
public:
    int helper(vector<int> &inDegree){
        for(int i=0;i<inDegree.size();i++){
            if(inDegree[i]==0) return i;
        }
        return -1;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // if there is a loop... return empty

        vector<vector<int>> map(numCourses); // index is the key value

        // topological sort.. calculate the inorder
        vector<int> inDegree(numCourses,0);
        for(auto &e: prerequisites){
            map[e[1]].push_back(e[0]);
            inDegree[e[0]]+=1;
        }

        //if no 0 found.. loop exist
        vector<int> result;
        vector<int> visited(numCourses);
        
        int allVisited=0;
        while(allVisited!=numCourses){
            int node=helper(inDegree);
            if(node==-1) return {};
            result.push_back(node);
            visited[node]=1;
            inDegree[node]=-1;
            for(auto &next:map[node]){
                inDegree[next]-=1;
            }
            allVisited++;
        }

        return result;
        
    }
};
