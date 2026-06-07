//https://www.hackerrank.com/contests/software-engineer-prep-kit/challenges/subarrays-given-sum-bounded-maximum/problem?isFullScreen=true



#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'countSubarraysWithSumAndMaxAtMost' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY nums
 *  2. LONG_INTEGER k
 *  3. LONG_INTEGER M
 */

long countSubarraysWithSumAndMaxAtMost(vector<int> nums, long k, long M) {
    long count=0;
    unordered_map<long long,long> prefix;
    long long summ=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>M) {
            summ=0;
            prefix.clear();
        }
        else {
            summ=summ+(long long)nums[i];
            if(summ==k) count++;
            long long f=(long long)summ-k;
            count=count+(long) prefix[f];
            prefix[summ]++;
        }
    }
    return count;
}

int main()
{
    string nums_count_temp;
    getline(cin, nums_count_temp);

    int nums_count = stoi(ltrim(rtrim(nums_count_temp)));

    vector<int> nums(nums_count);

    for (int i = 0; i < nums_count; i++) {
        string nums_item_temp;
        getline(cin, nums_item_temp);

        int nums_item = stoi(ltrim(rtrim(nums_item_temp)));

        nums[i] = nums_item;
    }

    string k_temp;
    getline(cin, k_temp);

    long k = stol(ltrim(rtrim(k_temp)));

    string M_temp;
    getline(cin, M_temp);

    long M = stol(ltrim(rtrim(M_temp)));

    long result = countSubarraysWithSumAndMaxAtMost(nums, k, M);

    cout << result << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
