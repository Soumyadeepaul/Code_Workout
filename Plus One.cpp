//https://leetcode.com/problems/plus-one/description/?envType=daily-question&envId=2026-01-01


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int l=digits.size()-1;
        digits[l]=digits[l]+1;
        int carry =digits[l]/10;
        digits[l]=digits[l]%10;
        for(int i=l-1;i>-1;i--){
            digits[i]=digits[i]+carry;
            if(digits[i]/10) carry=1;
            else carry =0;
            digits[i]=digits[i]%10;
        }
        if(carry==1) digits.insert(digits.begin(),1);
        return digits;
    }
};
