//https://leetcode.com/problems/encode-and-decode-tinyurl/description/

class Solution {
private:
    unordered_map<string,string> map;
    int count=1;
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string s="http://tinyurl.com/"+to_string(count++);
        map[s]=longUrl;
        return s;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return map[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
