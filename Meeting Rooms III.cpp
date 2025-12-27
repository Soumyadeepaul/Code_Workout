//https://leetcode.com/problems/meeting-rooms-iii/description/?envType=daily-question&envId=2025-12-27


class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        vector<int> track(n, 0);

        // free rooms -> smallest index
        priority_queue<int, vector<int>, greater<int>> freePQ;
        for(int i = 0; i < n; i++) freePQ.push(i);

        // busy rooms -> earliest end time
        priority_queue<pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>> busyPQ;

        queue<vector<int>> q(meetings.begin(), meetings.end());

        while(!q.empty()){
            long long start = q.front()[0];
            long long end = q.front()[1];
            long long dur = end - start;

            // free rooms that are done
            while(!busyPQ.empty() && busyPQ.top().first <= start){
                freePQ.push(busyPQ.top().second);
                busyPQ.pop();
            }

            if(!freePQ.empty()){
                int room = freePQ.top();
                freePQ.pop();
                busyPQ.push({end, room});
                track[room]++;
            } else {
                auto top = busyPQ.top();
                busyPQ.pop();
                busyPQ.push({top.first + dur, top.second});
                track[top.second]++;
            }

            q.pop();
        }

        int maxi = 0, idx = 0;
        for(int i = 0; i < n; i++){
            if(track[i] > maxi){
                maxi = track[i];
                idx = i;
            }
        }
        return idx;
    }
};
