//https://leetcode.com/problems/reveal-cards-in-increasing-order/description/


class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {

        sort(deck.begin(),deck.end());
        int l=deck.size();
        vector<int> result(l);

        deque<int> q;
        int idx=0;
        int extra=0;
        if(l&1){  // if odd one extra value in 1st half
            extra++;
        }
        //insert 1st half alternative
        for(int i=0;i<l/2+extra;i++){
            result[idx]=deck[i];
            idx+=2;
            q.push_back(idx-1);
        }
        if(l&1){
            q.pop_back();
            // if odd means last idx filled
            q.push_back(q.front());
            q.pop_front();
            // means skip then fill alt
        }

        for(int i=l/2+extra;i<l;i++){
            result[q.front()]=deck[i]; //place 
            q.pop_front();
            q.push_back(q.front());  //skip and add it to back
            q.pop_front();
        }

        return result;
        
    }
};
