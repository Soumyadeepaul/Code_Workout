//https://leetcode.com/problems/maximum-possible-number-by-binary-concatenation/description/?envType=problem-list-v2&envId=enumeration


class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        int l=nums.size();
        vector<string> store(l);
        for(int i=0;i<l;i++){
            string s="";
            int n=nums[i];
            while(n){
                s=to_string(n%2)+s;
                n/=2;
            }
            store[i]=s;
        }
        
        string a=store[0]+store[1]+store[2];
        string b=store[0]+store[2]+store[1];
        string c=store[1]+store[0]+store[2];
        string d=store[1]+store[2]+store[0];
        string e=store[2]+store[0]+store[1];
        string f=store[2]+store[1]+store[0];

        string result=max(a,max(b,max(c,max(d,max(e,f)))));
        int val=0,p=1;
        for(int i=result.size()-1;i>-1;i--){
            val+=(result[i]-'0')*p;
            p=p<<1;
        }
        return val;
    }
};
