//https://leetcode.com/problems/minimum-operations-to-make-binary-palindrome/description/

class Solution {
public:
    bool check(string &c){
        int i=0,j=c.size()-1;
        while(i<j){
            if(c[i++]!=c[j--]){
                return false;
            }
        }
        return true;
    }
    vector<int> minOperations(vector<int>& nums) {
        vector<bool> palindrome={false,true};
        vector<string> store={"0","1"};
        vector<int> idx={0,0};
        int maxi=*max_element(nums.begin(),nums.end());
        int temp=maxi;
        int count=0;
        while(temp){
            count++;
            temp>>=1;
        }
        int atMax=pow(2,count);
        int prefix=0,suffix=0;
        for(int i=2;i<atMax;i++){
            store.push_back(store[i>>1]+to_string(i&1));
            palindrome.push_back(check(store[i]));
            if(palindrome[i]==false) idx.push_back(++prefix);
            else{
                idx.push_back(0);
                prefix=0;
            }
        } 
        for(int i=atMax-1;i>-1;i--){
            if(palindrome[i]==false) idx[i]=min(idx[i],++suffix);
            else suffix=0;
        }
        vector<int> result;
        for(int i: nums){
            result.push_back(idx[i]);
        }
        return result;
    }
};
