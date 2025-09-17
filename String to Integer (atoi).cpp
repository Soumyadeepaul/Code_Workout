//https://leetcode.com/problems/string-to-integer-atoi/description/



class Solution {
public:
    int myAtoi(string s) {
        int minn=INT_MIN;
        int maxx=INT_MAX;
        int result=0;
        bool sign=false;
        bool digit=false;
        bool between=true;
        bool once=true;
        string digits="0123456789";
        for(int i=0;i<s.size();i++){
            if(s[i]==' ' && digit==false){ }
            else if((s[i]=='-' || s[i]=='+') && between==false) return 0;
            else if(s[i]=='-' && digit==false){
                sign=true;
                between=false;
            }
            else if(s[i]=='+' && digit==false){
                if(i+1<s.size() && s[i+1]==' '){return 0;}
                between=false;}
            else if(find(digits.begin(),digits.end(),s[i])!=digits.end()){
                int x=s[i]-'0';
                between=true;
                
                if(sign==true){
                    if((long)result*10-x<=minn) return INT_MIN;
                }
                else{
                    if((long)result*10+x>=maxx) return INT_MAX;
                }
                if(sign==true && once==true){
                    result=-x;
                    cout<<result;
                    if(x!=0){
                        once=false;
                    }
                }
                else if(sign==true){
                    result=result*10-x;
                }
                else{
                    result=result*10+x;
                }
                digit=true;
            }
            else{
                break;
            }
        }
        return result;
    }
};
