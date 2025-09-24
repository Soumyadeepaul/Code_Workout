//https://leetcode.com/problems/fraction-to-recurring-decimal/description/?envType=daily-question&envId=2025-09-24


class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {
        int sign=1;
        string result="";
        if(numerator==0) return "0";
        if ((numerator < 0) ^ (denominator < 0)) result += "-";

        // Convert to long to avoid overflow (especially INT_MIN)
        numerator = abs((long long)numerator);
        denominator = abs((long long)denominator);
        
        int index=0;
        int maxi=pow(10,4);
        unordered_map<int,int> map;
        long long rem=(long long)numerator%denominator;
        long long val=(long long)numerator/denominator;
        result+=to_string(val);
        if(rem==0){
            return result;
        }
        numerator=rem;
        result+='.';
        index=result.size();
        bool once;
        while(index<maxi){
            if(numerator<denominator){
                numerator=numerator*10;
            }
            rem=numerator%denominator;
            val=numerator/denominator;
            
            numerator=rem;
            index+=to_string(val).size();
            if(map.find(rem)==map.end()){
                map[rem]=index;
            }
            else{
                int found=map[rem];
                result+=to_string(val);
                result=result.substr(0,found)+'('+result.substr(found)+')';
                break;
            }
            result+=to_string(val);
            if(rem==0) break;
            
            
        }
        return result;
    }
};
