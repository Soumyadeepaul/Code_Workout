//https://leetcode.com/problems/count-number-of-trapezoids-i/description/?envType=daily-question&envId=2025-12-02


class Solution {
public:
    // int countTrapezoids(vector<vector<int>>& points) {
    //     unordered_map<int,int> yaxis; //freq
    //     for(vector<int> p:points){
    //         yaxis[p[1]]++;
    //     }
    //     //calculate each line combination choose 2
    //     vector<long long unsigned> linePermute;
    //     long long unsigned val;
    //     for(auto p:yaxis){
    //         int freq=yaxis[p.first];
    //         if(freq&1)
    //             val=(freq)*((freq-1)/2);
    //         else val=(freq/2)*(freq-1);
    //         if(val!=0 || val !=1)
    //             linePermute.push_back(val);
    //     }
    //     int result=1;
    //     int mod=pow(10,9)+7;
    //     // for(int i=0;i<linePermute.size();i++){
    //     //     for(int j=i+1;j<linePermute.size();j++){
    //     //         result=(result+linePermute[i]*linePermute[j])%mod;
    //     //     }
    //     // }
    //     int l=linePermute.size();
    //     for(int i=0;i<l;i++){
    //         result=(result*(int)pow(linePermute[i],l-1))%mod;   // pow exceeds limit
    //     }
    //     return result;



    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int> yaxis; //freq
        int result=0;
        int mod=pow(10,9)+7;
        for(vector<int> p:points){
            yaxis[p[1]]++;
        }
        //calculate each line combination choose 2
        
        long long unsigned edges;
        int totalSum=0;
        for(auto p:yaxis){
            int freq=yaxis[p.first];
            if(freq&1)
                edges=(freq)*((freq-1)/2);
            else edges=(freq/2)*(freq-1);  //edges as same level

            result=(result+edges*totalSum)%mod;
            totalSum=(totalSum+edges)%mod;   //summing he edges
            
        }
        

        return result;

    }
};
