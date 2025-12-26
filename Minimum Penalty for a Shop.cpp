//https://leetcode.com/problems/minimum-penalty-for-a-shop/description/?envType=daily-question&envId=2025-12-26


class Solution {
public:
    int bestClosingTime(string customers) {
        int l=customers.size()+1;
        vector<int> prefix(l,0);
        vector<int> suffix(l,0);
        for(int i=0;i<l-1;i++){
            // cout<<customers[l-i-2]<<endl;
            if(customers[i]=='N') prefix[i+1]=prefix[i]+1;
            else prefix[i+1]=prefix[i];

            if(customers[l-i-2]=='Y') suffix[l-i-2]=suffix[l-i-1]+1;
            else suffix[l-i-2]=suffix[l-i-1];
        }
        // for(int i:prefix) cout<<i<<" ";
        // cout<<endl;
        // for(int i:suffix) cout<<i<<" ";
        int result=INT_MAX,idx=0;
        for(int i=0;i<l;i++){
            if(prefix[i]+suffix[i]<result){
                result=prefix[i]+suffix[i];
                idx=i;
            }
        }

        return idx;

    }
};
