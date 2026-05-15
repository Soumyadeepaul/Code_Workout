//https://leetcode.com/problems/count-collisions-on-a-road/description/


class Solution {
public:
    int countCollisions(string directions) {
        stack<char> tracker;
        tracker.push(directions[0]);
        int count=0;
        for(int i=1;i<directions.size();i++){
            char current=directions[i];
            char top=tracker.top();
            if(current==top) tracker.push(current);
            else if(current=='L' && top=='R'){
                count+=2;
                //when after collide it get "S"... if there is any car moving R.. will collide later
                tracker.pop();
                while(!tracker.empty()){
                    if(tracker.top()=='R'){
                        count+=1;
                        tracker.pop();
                    }
                    else break;
                }
                tracker.push('S');
            }
            else if((current=='L' && top=='S')||(current=='S' && top=='R')){
                count+=1;
                //all the cars moving R will surely collide with S
                if(top=='R'){
                    tracker.pop();
                    while(!tracker.empty()){
                        if(tracker.top()=='R'){
                            count+=1;
                            tracker.pop();
                        }
                        else break;
                    }
                }
                tracker.push('S');
            }
            else tracker.push(current);
        }
        return count;
    }
};
