//https://leetcode.com/problems/find-smallest-letter-greater-than-target/?envType=study-plan-v2&envId=binary-search


class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int start=0;
        int end=letters.size();
        int mid;
        int result=0;
        while(start<end){
            mid=start+(end-start)/2;
            if(letters[mid]<=target){
                start=mid+1;
            }
            else{
                result=mid;
                end=mid;
            }
        }
        return letters[result];
    }
};
