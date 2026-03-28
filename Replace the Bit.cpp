//https://www.geeksforgeeks.org/problems/replace-the-bit3212/1


class Solution {
  public:
    int replaceBit(int n, int k) {
        // code here.
        int l=0, temp=n;
        while(temp){
            temp>>=1;
            l++;
        }
        if(l<k) return n;
        k=l-k;
        return n& (~(1<<k));
    }
};
