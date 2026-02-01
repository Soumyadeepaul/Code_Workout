//https://leetcode.com/contest/weekly-contest-487/problems/design-ride-sharing-system/description/


class RideSharingSystem {
private:
    queue<int> rider;
    queue<int> driver;
    unordered_set<int> cancelled;
    unordered_set<int> matched;
    unordered_set<int> riderInserted;
    
public:
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        rider.push(riderId);
        riderInserted.insert(riderId);
    }
    
    void addDriver(int driverId) {
        driver.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        while(!rider.empty() && !driver.empty()){
            int r=rider.front();
            rider.pop();
            if(cancelled.find(r)!=cancelled.end()){
                continue;
            }
            int d=driver.front();
            driver.pop();
            matched.insert(r);
            riderInserted.erase(r);
            return {d,r};
        }
        return {-1,-1};
    }
    
    void cancelRider(int riderId) {
        if(matched.find(riderId)!=matched.end()) return;
        if(riderInserted.find(riderId)!=riderInserted.end())
        cancelled.insert(riderId);
        return;
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */
