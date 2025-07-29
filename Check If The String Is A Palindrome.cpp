#

#include <bits/stdc++.h> 
bool checkPalindrome(string s)
{
    // Write your code here.
    int i=0;
    int j=s.length()-1;
    while(i<j){
        int x=s[i];
        if ((x>=48 && x<=57) || (x>=65 && x<=90) || (x>=97 && x<=122)){
            if (x>=97 && x<=122){
                s[i]=char(x-32);
            }
            int x=s[j];
            if ((x>=48 && x<=57) || (x>=65 && x<=90) || (x>=97 && x<=122)){
                if (x>=97 && x<=122){
                    s[j]=char(x-32);
                }
                // std::cout<<s[i]<<s[j];
                if (s[i]!=s[j]){
                    return 0;
                }
                else{
                    
                    i+=1;
                    j-=1;
                }
            }
            else{
                j-=1;
            }

        
        }
        else{
            i+=1;
        }
    }
    return "Yes";
}
