//https://leetcode.com/problems/largest-rectangle-in-histogram/description/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //TLE
        // int maximum=INT_MIN;
        // int l=heights.size();
        // int left,right;
        // int width;
        // for(int i=0;i<l;i++){
        //     left=i;
        //     right=i;
        //     while(left>-1){
        //         if(heights[left]>=heights[i]){
        //             left--;
        //         }
        //         else{
        //             break;
        //         }
               
        //     }
        //     while(right<l){
        //         if(heights[right]>=heights[i]){
        //             right++;
        //         }
        //         else{
        //             break;
        //         }
        //     }
        //     width=heights[i]*((right-1)-(left+1)+1);
        //     maximum=max(maximum,width);
        // }
        // return maximum;
        ///////////////////////////////////////////
        // previous smaller
        int l=heights.size();
        vector<int> prefixMinIdx(l,0);
        vector<int> suffixMinIdx(l,l);
        for(int i=1;i<l;i++){
            if(heights[i]<heights[i-1]){
                for(int k=i-1;k>-1;k--){
                    if(heights[i]>heights[k]){
                        prefixMinIdx[i]=k+1;
                        break;
                    }
                }
            }
            else if(heights[i]==heights[i-1]){
                prefixMinIdx[i]=prefixMinIdx[i-1];
            }
            else{
                prefixMinIdx[i]=i;
            }
            if(heights[l-1-i]<heights[l-i]){
                for(int k=l-i;k<l;k++){
                    if(heights[l-1-i]>heights[k]){
                        suffixMinIdx[l-1-i]=k;
                        break;
                    }
                }
            }
            else if(heights[l-1-i]==heights[l-i]){
                suffixMinIdx[l-1-i]=suffixMinIdx[l-i];
            }
            else{
                suffixMinIdx[l-1-i]=l-i;
            }
        }
        // for(int i:prefixMinIdx){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        // for(int i:suffixMinIdx){
        //     cout<<i<<" ";
        // }
        int area=0;
        for(int i=0;i<l;i++){
            area=max(area,heights[i]*(suffixMinIdx[i]-prefixMinIdx[i]));
        }

        return area;
        
        
    }
};
