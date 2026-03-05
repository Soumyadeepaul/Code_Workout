//https://leetcode.com/problems/largest-time-for-given-digits/description/


class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        unordered_map<int,int> map;
        for(int i:arr) map[i]++;
        for(int i=23;i>=0;i--){
            int n=i;
            int y=n%10;
            n/=10;
            int x=n;
            if(map[y]!=0){
                map[y]--;
                if(map[x]!=0){
                    map[x]--;
                    for(int j=59;j>=0;j--){
                        int m=j;
                        int b=m%10;
                        m/=10;
                        int a=m;
                        if(map[a]!=0){
                            map[a]--;
                            if(map[b]!=0){
                                return to_string(x)+to_string(y)+":"+to_string(a)+to_string(b);
                            }
                            map[a]++;
                        }
                    }
                    map[x]++;
                }
                map[y]++;
            }
        } 
        return "";
    }
};
