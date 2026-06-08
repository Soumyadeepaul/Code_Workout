//https://leetcode.com/problems/hand-of-straights/description/



class Solution {
public:
    void helper(priority_queue<int> &pq, unordered_map<int,int> &freq){
        for(auto p:freq){
            pq.push(p.first);
        }
    }
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int> freq;
        for(int i:hand) freq[i]++;
        priority_queue<int> pq;
        priority_queue<int> temp;
        helper(pq,freq);
        int prev=-1;
        int size=0;
        while(!pq.empty()){
            int element=pq.top();
            pq.pop();
            if(prev==-1){
                prev=element;
                size++;
                freq[element]--;
            }
            else if(element+1!=prev) return false;
            else{
                prev=element;
                size++;
                freq[element]--;
            }

            if(freq[element]==0) freq.erase(element);

            if(size==groupSize){
                pq=temp;
                prev=-1;
                helper(pq,freq);
                size=0;
            }
        }
        if(size!=0) return false;
        return true;
    }
};
