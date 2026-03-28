//https://www.geeksforgeeks.org/problems/set-the-rightmost-unset-bit4436/1


class Solution {
  public:
    int setBit(int n) {
        // Write Your Code here
        int l=1, temp=n;
        while(temp){
            if((temp&1)==0) break;
            l<<=1;
            temp>>=1;
        }
        return n|l;
    }
};
