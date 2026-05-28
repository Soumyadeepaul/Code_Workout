//https://leetcode.com/problems/bulb-switcher/description/


class Solution {
public:
    int bulbSwitch(int n) {
        // vector<int> divisors(n+1,0);

        // for(int i=2;i<n+1;i++){
        //     divisors[i]+=1;
        //     for(int j=i+i;j<n+1;j=j+i) divisors[j]+=1;
        // }
        // //as 1 was not considered in loop.. now odd is off and even in on
        // int count=0;
        // for(int i:divisors) if(!(i&1)) count++;
        // return count-1;

        ///////////////////////////////////////

        int gap=2;
        int count=0;
        for(int i=1;i<=n;){
            count++;
            i+=gap;
            gap+=2;
            i+=1;// next
        }
        return count;
    }
};
