//https://leetcode.com/contest/weekly-contest-487/problems/count-monobit-integers/description/


class Solution {
public:
    int countMonobit(int n) {
        int result=0, p=1;
        for(int i=0;i<10;i++){
            if(n==((p<<i)-1)){
                result++;
                break;
            }
        }
        while(n){
            n=n>>1;
            result++;
        }
        return result;
    }
};
