//https://leetcode.com/problems/minimum-genetic-mutation/description/?envType=problem-list-v2&envId=string

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string,int>> possible;  // to get the possible mutations from each mutation
        possible.push(make_pair(startGene,0)); // store mutation and no. of mutation
        unordered_set<string> checked; //already checked mutation from bank
        while(!possible.empty()){
            auto store=possible.front();
            string t=store.first;
            checked.insert(t);
            possible.pop();
            for(string b:bank){
                if(checked.find(b)!=checked.end()) continue;  // if checked dont repeat.. else loop
                int i=0,count=0;
                bool cant=false;
                //check
                while(i<8){
                    if(b[i]!=t[i]) count++;
                    if(count==2){  // if more than 1 change
                        cant=true;
                        break;
                    }
                    i++;
                }
                if(cant==false){
                    if(b==endGene) return store.second+1;  // if match found
                    possible.push(make_pair(b,store.second+1));
                }
            }

        }
        return -1;
    }
};
