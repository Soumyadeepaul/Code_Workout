//https://leetcode.com/problems/maximum-average-pass-ratio/description/?envType=daily-question&envId=2025-09-01


class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double result;
        vector<vector<double>> ratio;
        int index=0;
        vector<double> element;
        for(vector<int> i:classes){
            double x=(double)(i[0]+1)/(i[1]+1);
            double y=(double)(i[0])/(i[1]);
            double gain=(double)x-y; //gain  if added 1 student then whats the gain of ratio from previous value of its... the maximum gain will be added the student by 1 and update the gain with new gain..and loop
            //cout<<gain<<endl;
            element.push_back(gain);
            element.push_back(index);
            ratio.push_back(element);
            element.clear();
            index++;
        }

        make_heap(ratio.begin(),ratio.end());
        vector<double> values;
        int pass;
        int total;
        double newRatio;
        double oldRatio;
        while (extraStudents!=0){
            values=ratio.front();
            pop_heap(ratio.begin(),ratio.end());
            ratio.pop_back();
            classes[values[1]][0]++;
            classes[values[1]][1]++;
            pass=classes[values[1]][0];
            total=classes[values[1]][1];
            newRatio=(double)(pass+1)/(total+1);
            oldRatio=(double)pass/total;
            double gain=(double) newRatio-oldRatio;
            element.push_back(gain);
            //cout<<gain<<" "<<values[1]<<endl;
            element.push_back(values[1]);
            ratio.push_back(element);
            element.clear();
            push_heap(ratio.begin(),ratio.end());
            extraStudents--;
        }
        int n=classes.size();
        int i=0;
        while(i<n){
            cout<<classes[i][0]<<" "<<classes[i][1]<<endl;
            double ans=(double)classes[i][0]/classes[i][1];
            //cout<<ans<<endl;
            result=(double) result+ans;
            i++;
        }
        return result/n;
    }
};
