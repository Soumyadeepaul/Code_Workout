//https://leetcode.com/contest/biweekly-contest-170/problems/minimum-number-of-flips-to-reverse-binary-string/description/

class Solution {
public:
    int minimumFlips(int n) {
        //convert into binary
        string i;
        while(n){
            i+=to_string(n%2);
            n=n/2;
        }
        //check like palindrom
        int x=0,y=i.size()-1;
        int count=0;
        while(x<y){
            if(i[x++]!=i[y--]) count+=2;
        }
        return count;
    }
};
