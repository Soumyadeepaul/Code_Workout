//https://leetcode.com/problems/compare-version-numbers/description/?envType=daily-question&envId=2025-09-23


class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0;
        int j=0;
        int v1=version1.size();
        int v2=version2.size();
        vector<int> ver1;
        vector<int> ver2;
        string s;
        for(;i<v1;i++){
            if(version1[i]!='.'){
                s+=version1[i];
            }
            else{

                ver1.push_back(stoi(s));
                s="";
            }
        }

        ver1.push_back(stoi(s));
        s="";
        for(i=0;i<v2;i++){
            if(version2[i]!='.'){
                s+=version2[i];
            }
            else{
                ver2.push_back(stoi(s));
                s="";
            }
        }

        ver2.push_back(stoi(s));
        s="";

        for(;j<min(ver1.size(),ver2.size());j++){
            if(ver1[j]>ver2[j]) return 1;
            else if(ver1[j]<ver2[j])return -1;
        }
        while(j<ver1.size()){
            if(ver1[j]!=0){
                return 1;
            }
            j++;
        } 
        while(j<ver2.size()){
            if(ver2[j]!=0){
                return -1;
            }
            j++;
        } 
        return 0;
    }
};
