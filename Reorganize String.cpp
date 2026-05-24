//https://leetcode.com/problems/reorganize-string/description/


class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> freq;
        for(char c:s) freq[c]++;
        priority_queue<pair<int,char>> pq;
        for(auto p:freq) pq.push({p.second,p.first});

        string result="";
        char prev='1';
        pair<int,char> hold; //for alternative placing.. also not allowing for any consequetive placement
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            int remain=p.first;
            int ch=p.second;
            if(ch==NULL) continue; // helps to remove null
            if(ch==prev){
                break;
            }
            result+=ch;
            pq.push(hold);
            hold={NULL,NULL};
            if(remain-1!=0) hold={remain-1,ch};
            prev=ch;
        }
        return (result.size()==s.size()) ? result : "";
    }
};
