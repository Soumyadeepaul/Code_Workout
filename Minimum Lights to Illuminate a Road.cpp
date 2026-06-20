//


class Solution {
public:
    int minLights(vector<int>& lights) {
        vector<vector<int>> range;
        int l=lights.size();
        for(int i=0;i<l;i++){
            if(lights[i]!=0){
                range.push_back({max(0,i-lights[i]), min(l-1,i+lights[i])});
            }
        }
        //merge
        vector<vector<int>> merged;
        if(range.size()>0){
            int start=range[0][0];
            int end=range[0][1];
            for(int i=1;i<range.size();i++){
                if(end<range[i][0]){
                    merged.push_back({start,end});
                    start=range[i][0];
                    end=range[i][1];
                }
                else{
                    start=min(start,range[i][0]);
                    end=max(end,range[i][1]);
                }
            }
            merged.push_back({start,end});
        }
        merged.push_back({l,l});
        int count=0;
        int end=-1;

        for(int i=0;i<merged.size();i++){
            int gap=merged[i][0]-end-1; 
            count+=(gap+2)/3.0;
            end=merged[i][1];
        }
        
        
        
        return count;
    }
};
