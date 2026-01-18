//https://leetcode.com/contest/weekly-contest-485/problems/design-auction-system/description/

class AuctionSystem {
private:
    unordered_map<int,unordered_map<int,int>> store;
    struct cmp{
        bool operator()(const pair<int,int> &a, const pair<int,int> &b)const{
            if(a.first!=b.first) return a.first>b.first;

            return a.second>b.second;
                
        }
    };
    unordered_map<int,set<pair<int,int>,cmp>> itemBids;
public:
    AuctionSystem() {
        
    }
    void addBid(int userId, int itemId, int bidAmount) {
        if(store[itemId].count(userId)){
            itemBids[itemId].erase({store[itemId][userId],userId});
        }
        store[itemId][userId]=bidAmount;
        itemBids[itemId].insert({bidAmount,userId});
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        itemBids[itemId].erase({store[itemId][userId],userId});
        store[itemId][userId]=newAmount;
        itemBids[itemId].insert({newAmount,userId});
        
    }
    
    void removeBid(int userId, int itemId) {
        itemBids[itemId].erase({store[itemId][userId],userId});
        store[itemId].erase(userId);
    }
    
    int getHighestBidder(int itemId) {
        if(!itemBids.count(itemId) || itemBids[itemId].empty()) return -1;
        return itemBids[itemId].begin()->second;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */
