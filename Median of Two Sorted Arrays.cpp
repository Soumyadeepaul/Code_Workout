//https://leetcode.com/problems/median-of-two-sorted-arrays/description/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        if(n>m){
            return findMedianSortedArrays(nums2,nums1);
        }
        int symmetric=(n+m+1)/2;
        int start=0;
        int end=n;
        int mid;
        while(start<=end){
            mid=start+(end-start)/2;
            int l1=-1;
            int l2=-1;
            int r1=-1;
            int r2=-1;
            int mid2=symmetric-mid;
            if(mid==0){
                l1=-pow(10,9)+7;
            }
            else{
                l1=nums1[mid-1];
            }

            if(mid==n){
                r1=pow(10,9)+7;
            }
            else{
                r1=nums1[mid];
            }


            if(mid2==0){
                l2=-pow(10,9)+7;
            }
            else{
                l2=nums2[mid2-1];
            }

            if(mid2==m){
                r2=pow(10,9)+7;
            }
            else{
                r2=nums2[mid2];
            }

            if(l1<=r2 && l2<=r1){
                //symmetric
                
                if((n+m)%2==0){
                    int i=0;
                    if(l1>l2){
                        i=l1;
                    }
                    else{
                        i=l2;
                    }
                    int j=0;
                    if(r1>r2){
                        j=r2;
                    }
                    else{
                        j=r1;
                    }
                    float result= (i+j)/2.0;
                    return result;

                }
                else{
                    float result;
                    if(l1>l2){
                        result=l1;
                    }
                    else{
                        result=l2;
                    }
                    return result;
                }
            }
            else if(l1>r2){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
            
        }
        return 0.00000;
    }
};
