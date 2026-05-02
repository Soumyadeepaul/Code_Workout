//https://leetcode.com/problems/rotated-digits/description/?envType=daily-question&envId=2026-05-02



class Solution {
public:
    int rotatedDigits(int n) {
        vector<int> validity(n+1,0);
        int count=0;
        for(int i=0;i<=min(9,n);i++){
            if(i==7 || i==3 || i==4){}
            else if(i==0 || i==1 || i==8) {  //not valid now, but can be valid after if anything appened at 2 5 6 9
                validity[i]=2;
            }
            else{
                validity[i]=1;
                count++;
            }
        }
        for(int i=10;i<=n;i++){
            int previous=validity[i/10];
            int addNum=i%10;
            if(previous==0){continue;}
            
            else if(previous==2){
                if(addNum==7 || addNum==3 || addNum==4) {}
                else if(addNum==0 || addNum==1 || addNum==8) {
                    validity[i]=2;
                }
                else{
                    validity[i]=1;
                    count++;
                }
            }

            else{
                if(addNum==7 || addNum==3 || addNum==4) {}
                else{
                    validity[i]=1;
                    count++;
                }
            }
        }
        return count;
    }
};
