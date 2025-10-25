//https://leetcode.com/contest/biweekly-contest-168/problems/maximize-sum-of-squares-of-digits/description/



class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int maxi=0;
        int result;
        vector<int> digits(num,0);
        int i=9;
        for(int j=0;j<num;j++){
            if(i>sum){
                i=sum;
                digits[j]=i;
                sum-=i;
                break;
            }
            else{
                digits[j]=i;
                sum-=i;
            }
            
        }
        if(sum!=0) return ""; 
        string res="";
        for(int i:digits){
            res+=to_string(i);
        }
        return res;
    }
};©leetcode
