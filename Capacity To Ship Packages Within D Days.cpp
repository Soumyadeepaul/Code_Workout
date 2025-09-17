//https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/


class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int minn=*min_element(weights.begin(),weights.end());
        int maxx=accumulate(weights.begin(),weights.end(),0);
        if(days==1) return maxx;
        int bars;
        int l=weights.size();
        int count;
        int summ;
        int result;
        while(minn<=maxx){
            bars=minn+(maxx-minn)/2;
            count=0;
            summ=0;
            int i=0;
            int maximum=INT_MIN;
            while(i<l){
                summ+=weights[i];
                if(summ>bars){
                    count++;
                    maximum=max(maximum,summ-weights[i]);
                    summ=weights[i];
                }
                if(count>days-1){break;}
                i++;
            }
            maximum=max(maximum,summ);
            if(count==days-1){
                maxx=bars-1;
                result=maximum;
            }
            else if(count>days-1) minn=bars+1;
            else {
                maxx=bars-1;
                result=maximum;
            }
        }
        return result;
    }
};
