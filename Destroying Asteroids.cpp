//https://leetcode.com/problems/destroying-asteroids/

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        unsigned long long m=mass;
        unordered_map<int,int> freq;
        unordered_set<int> unique;
        for(int i:asteroids){
            freq[i]++;
            unique.insert(i);
        }
        vector<int> uni(unique.begin(),unique.end());
        sort(uni.begin(),uni.end());
        for(int i:uni){
            if(m>=i) m=(unsigned long long) m+((unsigned long long)i*freq[i]);
            else return false;
        }
        return true;
    }
};
