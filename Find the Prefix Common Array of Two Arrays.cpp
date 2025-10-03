//https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/


class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int l=A.size();
        vector<int> C (l,0);
        C[l-1]=l;
        int temp=l-1;
        unordered_set<int> alreadySubtracted;
        while(temp>0){
            if(A[temp]==B[temp]){
                C[temp-1]=C[temp]-1;
                alreadySubtracted.insert(A[temp]);
            }
            else{
                auto a=alreadySubtracted.find(A[temp]);
                auto b=alreadySubtracted.find(B[temp]);
                if(a==alreadySubtracted.end() && b==alreadySubtracted.end()){ //not in set
                    C[temp-1]=C[temp]-2;
                    alreadySubtracted.insert(A[temp]);
                    alreadySubtracted.insert(B[temp]);
                }
                else if(a==alreadySubtracted.end()){
                    C[temp-1]=C[temp]-1;
                    alreadySubtracted.insert(A[temp]);
                    
                }
                else if (b==alreadySubtracted.end()){
                    C[temp-1]=C[temp]-1;
                    alreadySubtracted.insert(B[temp]);
                }
                else{ //already present in set means we already subtracted
                    C[temp-1]=C[temp];
                }
            }

            temp--;
        }
        return C;
    }
};
