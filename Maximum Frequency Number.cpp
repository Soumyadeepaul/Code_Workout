#

int maximumFrequency(vector<int> &arr, int n)
{
    //Write your code here
    unordered_map<int,vector<int>> hashmap;
    for(int i=0;i<n;i++){
        if(hashmap.find(arr[i])!=hashmap.end()){
            hashmap[arr[i]][0]=hashmap[arr[i]][0]+1;
        }
        else{
            hashmap.insert({arr[i],{1,i}});
        }
    }
    int maximum=-1;
    int result;
    int pos;
    for(auto &i:hashmap){
        if(i.second[0]>maximum){
            maximum=i.second[0];
            result=i.first;
            pos=i.second[1];
        }
        else if(i.second[0]==maximum){
            if(pos>i.second[1]){
                pos=i.second[1];
                result=i.first;
            }
        }
    }
    return result;
}
