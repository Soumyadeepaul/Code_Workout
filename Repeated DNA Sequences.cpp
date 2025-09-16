//https://leetcode.com/problems/repeated-dna-sequences/description/?envType=problem-list-v2&envId=string


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int l=s.size();
        vector<string> result;
        if(l<10) return result;
        unordered_set<string> seqs; 
        string seq;
        for(int i=0;i<=l-10;i++){
            seq=s.substr(i,10);
            if(seqs.find(seq)!=seqs.end() && find(result.begin(),result.end(),seq)==result.end()){
                result.push_back(seq);
            }
            //cout<<seq<<endl;
            seqs.insert(seq);
        }
        return result;
    }
};
