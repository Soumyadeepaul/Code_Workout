//https://leetcode.com/problems/ugly-number-ii/description/


class Solution {
public:
    int nthUglyNumber(int n) {

        // using ll = long long;
        // priority_queue<ll, vector<ll>, greater<ll>> pq;
        // unordered_set<ll> seen;

        priority_queue<long long> q;
        unordered_set<long long> dup;
        q.push(-1);
        int count=1;
        int get;
        while(count<n){
            get=-(long long)q.top();
            if(get>0) get=-get;
            count++;
            q.pop();
            if(dup.find((long long)get*2)==dup.end()){
                dup.insert((long long)get*2);
                q.push((long long)get*2);
            }
            if(dup.find((long long)get*3)==dup.end()){
                dup.insert((long long)get*3);
                q.push((long long)get*3);
            }
            if(dup.find((long long)get*5)==dup.end()){
                dup.insert((long long)get*5);
                q.push((long long)get*5);
            }
        }
        return -(long long)q.top();
    }
};
