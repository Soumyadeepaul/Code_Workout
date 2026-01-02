//https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/?envType=problem-list-v2&envId=hash-table


// class Solution {
// public:
//     struct Tri{
//         Tri* zero=NULL;
//         Tri* one=NULL;
//     };
//     int getMax(string t,Tri* node, int &maxiDiffIdx){
//         string b="";
//         int p=1;
//         Tri* temp=node;
//         int diff=34;
//         for(int i=0;i<32;i++){
//             if(t[i]=='1'){
//                 if(temp->zero!=NULL){
//                     diff=(diff<34)? i:34;
//                     b+='0';
//                     temp=temp->zero;
//                 }
//                 else{
//                     b+='1';
//                     temp=temp->one;
//                 }
//             }
//             else{
//                 if(temp->one!=NULL){
//                     diff=(diff<34)? i:34;
//                     b+='1';
//                     temp=temp->one;
//                 }
//                 else{
//                     b+='0';
//                     temp=temp->zero;
//                 }
//             }
//             if(diff==34){}
//             else{
//                 if(diff>maxiDiffIdx){
//                     return 0;
//                 }
//                 else{
//                     maxiDiffIdx=min(diff,maxiDiffIdx);
//                 }
//             }
//         }
//         int x=0,y=0;
//         for(int i=31;i>-1;i--){
//             x+= (t[i]=='1') ? p:0;
//             y+= (b[i]=='1') ? p:0;
//             p=p<<1;
//         }
//         return x^y;

//     }
//     int findMaximumXOR(vector<int>& nums) {
//         //TLE
//         // unordered_set<int> map;
//         // int maxx=0;
//         // for(int i=0;i<nums.size();i++){
//         //     if(map.find(nums[i])==map.end()){
//         //         for(int j=i+1;j<nums.size();j++){
//         //             maxx=max(maxx,nums[i]^nums[j]);
//         //         }
//         //     }
//         //     map.insert(nums[i]);
//         // }
//         // return maxx;
//         //////////////////////////////////////////
//         Tri* head=new Tri();
//         vector<string> trash;
//         for(int i:nums){
//             int n=i;
//             string store="";
//             while(n){
//                 store=to_string(n%2)+store;
//                 n/=2;
//             }
//             int l=store.size();
//             store=string(32-l,'0')+store;
//             Tri* temp=head;
//             trash.push_back(store);
//             for(int i=0;i<32;i++){
//                 if(store[i]=='0'){
//                     if(temp->zero==NULL){
//                         Tri* node= new Tri();
//                         temp->zero=node;
//                     }
//                     temp=temp->zero;
//                 }
//                 else{
//                     if(temp->one==NULL){
//                         Tri* node= new Tri();
//                         temp->one=node;
//                     }
//                     temp=temp->one;
//                 }
//             }
//         }
//         int maxi=0;
//         int maxiDiffIdx=-1;
//         for(string t:trash){
//             maxi=max(maxi,getMax(t,head,maxiDiffIdx));
//         }
//         return maxi;
//     }
// };

///////////////////////////////////////////////////////////////
class Solution {
public:
    struct Tri{
        Tri* zero = nullptr;
        Tri* one = nullptr;
    };

    int getMax(int num, Tri* node) {
        Tri* temp = node;
        int xorVal = 0;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(bit) { // current bit is 1
                if(temp->zero) {
                    xorVal |= (1 << i); // take 0 to maximize XOR
                    temp = temp->zero;
                } else {
                    temp = temp->one;
                }
            } else { // current bit is 0
                if(temp->one) {
                    xorVal |= (1 << i); // take 1 to maximize XOR
                    temp = temp->one;
                } else {
                    temp = temp->zero;
                }
            }
        }
        return xorVal;
    }

    int findMaximumXOR(vector<int>& nums) {
        Tri* head = new Tri();

        // Insert all numbers into the trie
        for(int num : nums) {
            Tri* temp = head;
            for(int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;
                if(bit) {
                    if(!temp->one) temp->one = new Tri();
                    temp = temp->one;
                } else {
                    if(!temp->zero) temp->zero = new Tri();
                    temp = temp->zero;
                }
            }
        }

        int maxi = 0;
        for(int num : nums) {
            maxi = max(maxi, getMax(num, head));
        }

        return maxi;
    }
};
