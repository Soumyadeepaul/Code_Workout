#

#include <bits/stdc++.h> 
vector < int > findAllSelfDividingNumbers(int lower, int upper) {
    // Write your code here
    vector <int> result;
    for (int i=lower;i<=upper;i++){
        int k=i;
        int possible=1;
        while (k){
            int rem=k%10;
            k=k/10;
            if (rem==0){
                possible=0;
                break;
            }
            if(i%rem!=0){
                possible=0;
                break;
            }
            
        }
        if (possible==1){
            result.push_back(i);
        }
    }
    return result;
}
