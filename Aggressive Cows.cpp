//https://www.geeksforgeeks.org/problems/aggressive-cows/1


class Solution {
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(),stalls.end());
        int start=0; //minimum gap is 0
        int size=stalls.size();
        int end=stalls[size-1]; //maximum gap is max
        int gap;
        int placed;
        int i;
        int j;
        int result;
        while(start<=end){
            placed=1;
            gap=start+((end-start)/2);
            i=0;
            j=i+1;
            while(j<size){
                if(stalls[j]-stalls[i]>=gap){
                    placed++;
                    i=j;
                    if(placed==k){
                        break;
                    }
                    
                }
                j++;
            }
            //cout<<gap<<" "<<placed<<endl;
            if(placed>=k){
                if(placed==k) result=gap;
                start=gap+1;
            }
            else{
                end=gap-1;
            }
            
        }
        return result;
    }
};
