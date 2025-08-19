//Find the unique element in sorted array where other element has only 2 occurance.


#include <bits/stdc++.h>
using namespace std;


int main(){
    int arr[]={1,2,2,3,3,4,4,8,8};
    int length=sizeof(arr)/sizeof(arr[0]);
    int start=0;
    int end=length-1;
    int mid;
    while(start<=end){
        mid=start+(end-start)/2;
        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]){
            cout<<arr[mid];
            break;
        }
        if(mid%2==0){  //even
            if(arr[mid]==arr[mid+1]){
                start=mid+2;
            }
            else if(arr[mid]!=arr[mid+1]){
                end=mid;
            }
        }
        else{   //odd
            if(arr[mid]==arr[mid-1]){
                start=mid+1;
            }
            else if(arr[mid]!=arr[mid-1]){
                end=mid-1;
            }
            
        }
    }
}
