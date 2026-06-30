//https://www.hackerrank.com/contests/software-engineer-prep-kit/challenges/max-unique-substring-length-in-session/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;



/*
 * Complete the 'maxDistinctSubstringLengthInSessions' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING sessionString as parameter.
 */
int maxDistinctSubstringLengthInSessions(string sessionString) {
    int i=0,j=0;
    int result=0;
    unordered_set<char> uni;
    while (j<sessionString.size()){
        if(sessionString[j]=='*'){
            result=max(result,j-i);
            uni.clear();
            j++;
            i=j;
        }
        else if(uni.find(sessionString[j])==uni.end()){
            uni.insert(sessionString[j]);
            j++;
        }
        else{
            result=max(result,j-i);
            while(i!=j and sessionString[i]!=sessionString[j]){
                uni.erase(sessionString[i]);
                i++;
            }
            j++;
            i++;
        }
    }
    result=max(result,j-i);
    return result;    
}

int main()
{
    string sessionString;
    getline(cin, sessionString);

    int result = maxDistinctSubstringLengthInSessions(sessionString);

    cout << result << "\n";

    return 0;
}
