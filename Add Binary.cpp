//https://leetcode.com/problems/add-binary/description/?envType=daily-question&envId=2026-02-15


class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size()<b.size()) return addBinary(b,a);
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());

        int carry=0;
        string result="";
        int i=0;
        for(;i<b.size();i++){
            if(a[i]=='1' && b[i]=='1' && carry==1){
                result+='1';
            }
            else if(a[i]=='1' && b[i]=='1' && carry==0){
                result+='0';
                carry=1;
            }
            else if((a[i]=='1' || b[i]=='1') && carry ==1){
                result+='0';
                carry=1;
            }
            else if((a[i]=='1' || b[i]=='1') && carry ==0){
                result+='1';
            }
            else if((a[i]=='0' && b[i]=='0') && carry ==0) result+='0';
            else if((a[i]=='0' && b[i]=='0') && carry ==1){
                result+='1';
                carry=0;
            }
        }
        while(i<a.size()){
            if((a[i]=='1' && carry == 1) || (a[i]=='0' && carry == 0)){
                result+='0';
            }
            else if((a[i]=='1' && carry == 0) || (a[i]=='0' && carry == 1) ){
                result+='1';
                carry=0;
            }
            i++;
        }
        if(carry==1) result+='1';
        reverse(result.begin(),result.end());
        return result;
    }
};
