//https://leetcode.com/problems/beautiful-towers-i/description/

class Solution {
public:
    long long check(vector<int> &maxHeights, int &idx){
        long long result=0;
        int i=idx-1, j=idx+1;
        int prev=maxHeights[i+1];
        while(i>-1){
            prev=min(prev,maxHeights[i]);
            result+=prev;
            i--;
        }
        prev=maxHeights[j-1];
        while(j<maxHeights.size()){
            prev=min(prev,maxHeights[j]);
            result+=prev;
            j++;
        }
        return result+maxHeights[idx];
    }

    vector<int> peak(vector<int>& maxHeights){
        vector<int> peaks(maxHeights.size(),0);
        for(int i=1;i<maxHeights.size()-1;i++){
            if(maxHeights[i]>=maxHeights[i-1] && maxHeights[i+1]<=maxHeights[i]){
                peaks[i]=1;
            }
        }
        peaks[0]=1;
        peaks[peaks.size()-1]=1;
        return peaks;
    }
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        long long maxi=0;
        long long result=0;
        vector<int> peaks=peak(maxHeights);
        int summ=accumulate(peaks.begin(),peaks.end(),0);
        if(summ==peaks.size()){
            for(int i:maxHeights) result+=i;
            return result;
        }
        for(int i=0;i<maxHeights.size();i++){
            if(peaks[i]==1) result=max(result, check(maxHeights,i));
        }
        return result;
        
        
    }
};
