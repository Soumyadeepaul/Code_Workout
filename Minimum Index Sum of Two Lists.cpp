//https://leetcode.com/problems/minimum-index-sum-of-two-lists/?envType=problem-list-v2&envId=hash-table


class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> map;
        vector<string> result;
        int minn=INT_MAX;
        for(int i=0;i<list1.size();i++){
            for(int j=0;j<list2.size();j++){
                if(list1[i]==list2[j]){
                    map[list1[i]]=i+j;
                    if(minn>map[list1[i]]){
                        minn=i+j;
                        result.clear();
                        result.push_back(list1[i]);
                    }
                    else if(minn==i+j){
                        result.push_back(list1[i]);
                    }
                    break;
                }
            }
        }
        return result;
    }
};
