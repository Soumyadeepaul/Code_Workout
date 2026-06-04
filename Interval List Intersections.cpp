//https://leetcode.com/problems/interval-list-intersections/description/



class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> result;

        int i=0, j=0, li=firstList.size(), lj=secondList.size();
        if(li==0 || lj==0) return {};
        
        while(i<li && j<lj){
            int start1=firstList[i][0];
            int start2=secondList[j][0];
            int end1=firstList[i][1];
            int end2=secondList[j][1];
            if(end1<start2){
                i++;
            }
            else if (start1>end2){
                j++;
            }
            else{
                int s=max(start1,start2);
                int e=min(end1,end2);
                result.push_back({s,e});
                if(end1>end2) j++;
                else i++;
            }
        }
        return result;
    }
};
