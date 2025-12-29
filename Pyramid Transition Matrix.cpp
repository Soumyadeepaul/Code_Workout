//https://leetcode.com/problems/pyramid-transition-matrix/description/?envType=daily-question&envId=2025-12-29


class Solution {
public:
    bool backtrack(string bottom, string create, int idx,unordered_map<string,deque<char>> &map, unordered_set<string> &dp){       
        if(idx==0 && bottom.size()==1) return true;
        if(idx==bottom.size()-1){            
            if(backtrack(create,"",0,map,dp)) return true;
            dp.insert(create);
            return false;
        }
        if(dp.find(bottom)!=dp.end()) return false;

        deque<char> track;
        string s=string(1,bottom[idx])+string(1,bottom[idx+1]);
        while(!map[s].empty()){
            create+=map[s].front();
            track.push_back(map[s].front());
            if(backtrack(bottom,create,idx+1,map,dp)) return true;
            create.pop_back();
            map[s].pop_front();
        }
        map[s]=track;
        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string,deque<char>> map;
        for(string a: allowed){
            map[string(1,a[0])+string(1,a[1])].push_back(a[2]);
        }
        string create="";
        unordered_set<string> dp;
        if(backtrack(bottom,create,0,map,dp)) return true;
        return false;
        
    }
};
