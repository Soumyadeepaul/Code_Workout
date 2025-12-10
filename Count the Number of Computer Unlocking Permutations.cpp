//https://leetcode.com/problems/count-the-number-of-computer-unlocking-permutations/description/?envType=daily-question&envId=2025-12-10


class Solution {
public:
    int p=pow(10,9)+7;
    long long fact(int n){
        if(n==1) return 1;
        return (n*fact(n-1))%p;
    }
    int countPermutations(vector<int>& complexity) {
        int minn=*min_element(complexity.begin(),complexity.end());
        if(minn!=complexity[0]) return 0;
        for(int i=1;i<complexity.size();i++){
            if(minn==complexity[i]) return 0;
        }
        return fact(complexity.size()-1);
    }
};
