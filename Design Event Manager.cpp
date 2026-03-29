//https://leetcode.com/contest/weekly-contest-495/problems/design-event-manager/


class EventManager {
private:
    map<int,set<int>> mp;
    unordered_map<int,int> priorityKeeper;
public:
    EventManager(vector<vector<int>>& events) {
        for(vector<int> e:events){
            mp[e[1]].insert(e[0]);
            priorityKeeper[e[0]]=e[1];
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        if(priorityKeeper.count(eventId)){
            int p=priorityKeeper[eventId];
            mp[p].erase(eventId);
            if(mp[p].empty()) mp.erase(p);
        }
        
        priorityKeeper[eventId]=newPriority;
        mp[newPriority].insert(eventId);
    }
    
    int pollHighest() {
        if(mp.empty()) return -1;
        auto it=prev(mp.end());
        int p=it->first;
        int e=*it->second.begin();

        it->second.erase(it->second.begin());

        if(it->second.empty()) mp.erase(p);

        priorityKeeper.erase(e);

        return e;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */
