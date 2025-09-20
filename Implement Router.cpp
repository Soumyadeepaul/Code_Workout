//MLE & TLE
//https://leetcode.com/problems/implement-router/description/?envType=daily-question&envId=2025-09-20


class Router {
public:
    struct route{
        route* previous=nullptr;
        int source;
        int destination;
        int timestamp;
        route* next=nullptr;
    };
    int limit=0;
    unordered_set<string> duplicateCheck;
    route* tail=new route();
    route* head=new route();
    unordered_map<int,vector<int>> counter;
    int memoryLimit;
public:
    Router(int memoryLimit) {
        this->memoryLimit=memoryLimit;
        tail->previous=head;
        head->next=tail;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        string routing=to_string(source)+":"+to_string(destination)+":"+to_string(timestamp);
        if(duplicateCheck.find(routing)!=duplicateCheck.end()){//if duplicate
            return false;
        }
        duplicateCheck.insert(routing);
        if(limit==memoryLimit){
            // remove the oldest -> close to head
            route* node=head->next;
            int s=node->source;
            int d=node->destination;
            int t=node->timestamp;
            node->previous->next=node->next;
            node->next->previous=node->previous;
            delete node;
            string routing=to_string(s)+":"+to_string(d)+":"+to_string(t);
            duplicateCheck.erase(routing);
            limit--;
            ////////
            auto it=find(counter[d].begin(),counter[d].end(),t);
            if(it!=counter[d].end()){
                counter[d].erase(it);
            }
        }
        // insert from tail
        route* node=new route();
        node->source=source;
        node->destination=destination;
        node->timestamp=timestamp;
        node->previous=tail->previous;
        node->next=tail;
        tail->previous->next=node;
        tail->previous=node;
        counter[destination].push_back(timestamp);
        limit++;
        return true;
    }
    
    vector<int> forwardPacket() {
        //remove from head;
        route* node=head->next;
        if(node==tail){
            vector<int> empty;
            return empty;
        }
        int s=node->source;
        int d=node->destination;
        int t=node->timestamp;
        node->previous->next=node->next;
        node->next->previous=node->previous;
        delete node;
        vector<int> remove={s,d,t};
        string routing=to_string(s)+":"+to_string(d)+":"+to_string(t);
        duplicateCheck.erase(routing);
        limit--;
        auto it=find(counter[d].begin(),counter[d].end(),t);
        if(it!=counter[d].end()){
            counter[d].erase(it);
        }
        return remove;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        vector<int> get= counter[destination];
        int count=0;
        for(int i:get){
            if(i>=startTime && i<=endTime){
                count++;
            }
        }
        return count;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
