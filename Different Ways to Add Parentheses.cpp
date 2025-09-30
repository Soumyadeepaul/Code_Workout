//https://leetcode.com/problems/different-ways-to-add-parentheses/


class Solution {
public:
    vector<int> makeFun(string &exp,int left,int right){
        vector<int> res;
        for(int i=left;i<=right;i++){
            if(exp[i]=='*'|| exp[i]=='+'|| exp[i]=='-'){// divide only when operation is there
                vector<int> nums1=makeFun(exp,left,i-1);// left side
                vector<int> nums2=makeFun(exp,i+1,right);//right side
                // we will have multiple answers from left and right side...
                // a1, a2 ...     b1, b2....
                // a1+b1   a1+b2 .... a2+b1 a2+b2...   2 independent no. of possible sol. is n*m
                for(int x:nums1){
                    for(int y:nums2){
                        if(exp[i]=='*') res.push_back(x*y);
                        else if(exp[i]=='+') res.push_back(x+y);
                        else if(exp[i]=='-') res.push_back(x-y);
                    }
                }
            }
        }
        if(res.empty()){ // when there is no operation... the part will only have integer
            string x=exp.substr(left,right+1);
            res.push_back(stoi(x));
        }
        return res;

    }
    vector<int> diffWaysToCompute(string exp) {
        vector<int> result;
        int l=exp.size();
        result=makeFun(exp,0,l-1);
        return result;
    }
};
