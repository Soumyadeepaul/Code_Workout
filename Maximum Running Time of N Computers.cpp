//https://leetcode.com/problems/maximum-running-time-of-n-computers/description/?envType=daily-question&envId=2025-12-01

class Solution {
public:
    bool possible(vector<int>& batteries,long long int time, int &n){
        long long int contri=0;

        for(int i:batteries){
            contri+=min(time,1LL*i);
            if(contri>=n*time) return true;
        }
        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long int start=0;
        long long int end= pow(10,14);
        long long int mid;
        long long int result=0;
        sort(batteries.rbegin(),batteries.rend());
        while(start<=end){
            mid=(start+end)/2;
            if(possible(batteries,mid,n)==true){
                result=max(result,mid);
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return result;

    }
};
