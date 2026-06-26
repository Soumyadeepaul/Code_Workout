//

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;
        int idx=0;
        for(int i=1;i<=n;i++){
            result.emplace_back("Push");
            if(i!=target[idx]) result.emplace_back("Pop");
            else {
                idx++;
                if(idx==target.size()) break;
            }
        }
        return result;
    }
};
