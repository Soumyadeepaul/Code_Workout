//https://leetcode.com/problems/next-greater-numerically-balanced-number/description/?envType=daily-question&envId=2025-10-24



class Solution {
public:
    int nextBeautifulNumber(int n) {

        int l=to_string(n).size();
        // check for l and l+1
        //l
        char c=l+'0';
        string s=string(l,c);
        int ans=stoi(s);
        bool increased=false;
        if(stoi(s)<=n){
            s=string(l+1,l+1+'0');
            l=l+1;
            ans=stoi(s);
            increased=true;
        }
        //
        if (increased==true){
            n=pow(10,l-1);
        }
        for(int i=n+1;i<ans;i++){
            //check
            vector<int> check(10,0);
            int store=i;
            while(store){
                int rem=store%10;
                if(rem==0) break;
                check[rem]++;
                if(check[rem]>rem) break;
                store=store/10;
            }
            if(store==0){
                bool success=true;
                for(int x=1;x<10;x++){
                    if(check[x]!=0 && x!=check[x]){
                        success=false;
                        break;
                    }
                }
                if(success==true)
                return i;
            }
        }

        return ans;
    }
};
