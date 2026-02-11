//https://leetcode.com/problems/my-calendar-ii/description/

class MyCalendarTwo {
private:
    vector<vector<int>> booked;
    vector<vector<int>> overlap; 
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        //check with overlap
        for(auto &p: overlap){
            if(endTime<=p[0] || startTime>=p[1]){} // non overlap
            else return false;
        }   

        // insert in booked and overlap
        for( auto &p:booked){
            if(endTime<=p[0] || startTime>=p[1]){} // non overlap
            else{
                overlap.push_back({max(startTime,p[0]),min(endTime,p[1])});
            }
        }
        booked.push_back({startTime,endTime});

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */
