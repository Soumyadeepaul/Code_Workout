//https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/description/?envType=daily-question&envId=2025-09-08

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> result;
        int i=1;
        int x;
        int y;
        bool x0;
        bool y0;
        while(i<=n-i){
            //check no zero
            x=i;
            y=n-i;
            x0=0;
            y0=0;
            //cout<<x<<" "<<y<<endl;
            while(x>=10){
                if(x%10==0){
                    x0=1;
                    break;
                }
                x=x/10;
            }
            if(x0==1){
                i++;
                continue;
            }
            while(y>=10){
                if(y%10==0){
                    y0=1;
                    break;
                }
                y=y/10;
            }
            if(y0==1){
                i++;
                continue;
            }
            if(x0==0 && y0==0){
                result.push_back(i);
                result.push_back(n-i);
                break;
            }

        }

        return result;
    }
};
