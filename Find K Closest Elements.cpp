//https://leetcode.com/problems/find-k-closest-elements/submissions/1788087449/?envType=study-plan-v2&envId=binary-search


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // get in nearest index;
        int start=0;
        int end=arr.size();
        int mid=0;
        int resultIdx=0;
        while(start<end){
            mid=start+(end-start)/2;
            if(arr[mid]==x){
                resultIdx=mid;
                break;
            }
            else if(arr[mid]>x){
                end=mid;
                // resultIdx=mid;
            }
            else{
                resultIdx=mid;
                start=mid+1;

            }
        }
        // cout<<resultIdx;
        vector<int> result;
        int l=arr.size();
        int i=resultIdx;
        int j=resultIdx+1;
        while(k!=0){
            if(i>-1 && j<l){
                // cout<<arr[i]<<" "<<arr[j]<<endl;
                if(abs(arr[i]-x)==abs(arr[j]-x)){
                    result.insert(result.begin(),arr[i--]);
                }
                else if(abs(arr[i]-x)<abs(arr[j]-x)){
                    result.insert(result.begin(),arr[i--]);
                }
                else {
                    result.push_back(arr[j++]);
                }
            }
            else if(i==-1){
                result.push_back(arr[j++]);
            }
            else if(j==l){
                result.insert(result.begin(),arr[i--]);
            }
            k--;
        }
        return result;
    }
};
