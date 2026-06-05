//https://leetcode.com/problems/word-ladder/description/


class Solution {
public:
    bool diff(string &a, string &b){
        int skip=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i] && skip==0) skip++;
            else if(a[i]!=b[i] && skip==1) return false;
        }
        return true;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string>> graph;
        for(string b:wordList){
            if(diff(beginWord,b)) graph[beginWord].push_back(b);
        }

        for(int i=0;i<wordList.size();i++){
            if(wordList[i]==beginWord) continue;
            for(int j=i+1;j<wordList.size();j++){
                if(diff(wordList[i],wordList[j])) {
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }

        // for(auto p:graph){
        //     cout<<p.first<<"     ";
        //     for(auto q:p.second) cout<<q<<" ";
        //     cout<<endl;
        // }

        priority_queue<pair<int,string>, vector<pair<int,string>>, greater<pair<int,string>>> pq;
        unordered_set<string> visited;
        pq.push({1,beginWord});
        while(!pq.empty()){
            auto store=pq.top();
            pq.pop();
            string word=store.second;
            int count=store.first;

            // cout<<word<<" "<<count<<endl;

            if(word==endWord) return count;

            visited.insert(word);

            for(auto nei:graph[word]){
                if(!visited.count(nei)) pq.push({count+1,nei});
            }
        }

        return 0;
    }
};
