//https://leetcode.com/problems/robot-collisions/description/?envType=daily-question&envId=2026-04-01


class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        // L=76 and R=82
        vector<vector<int>> store;
        for(int i=0;i<positions.size();i++){
            store.push_back({positions[i], healths[i], directions[i], i});
        }
        sort(store.begin(),store.end());

        stack<vector<int>> track;
        track.push(store[0]);
        for(int i=1;i<store.size();i++){
            if(track.empty()) track.push(store[i]);
            else{
                while(!track.empty()){
                    vector<int> temp=track.top();
                    if(temp[2]==store[i][2]){  //same direction
                        track.push(store[i]);
                        break;
                    }
                    else{
                        if(temp[2]==76 && store[i][2]==82){ //at left side and going left.. and new one is at right and going right.. no meaning of collision
                            track.push(store[i]);
                            break;
                        }
                        else if(temp[1]>store[i][1]){ // lesser health
                            track.pop();
                            temp[1]--;
                            if(temp[1]>0){
                                track.push(temp);
                            }
                            break;
                        }
                        else if(temp[1]==store[i][1]){
                            
                            track.pop();
                            break;
                        }
                        else{   //if larger
                            track.pop();
                            store[i][1]--;
                            if(store[i][1]==0) break;
                            if(track.empty()){
                                if(store[i][1]>0){
                                    track.push(store[i]);
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }


        vector<vector<int>> result;
        while(!track.empty()){
            vector<int> temp=track.top();
            track.pop();
            result.push_back({temp[3],temp[1]});
        }
        sort(result.begin(),result.end());
        vector<int> ans;
        for(int i=0;i<result.size();i++){
            ans.emplace_back(result[i][1]);
        }

        return ans;

    }
};
