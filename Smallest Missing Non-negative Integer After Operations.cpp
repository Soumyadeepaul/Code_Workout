//https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/description/?envType=daily-question&envId=2025-10-16


class Solution:
    def findSmallestInteger(self, nums, value):
        from collections import defaultdict

        freq = defaultdict(int)
        for i in nums:
            freq[i % value] += 1

        result = []
        for k, v in freq.items():
            for i in range(v):
                result.append(k + i * value)

        result.sort()

        find = 0
        i = 0
        while i < len(result):
            if result[i] == find:
                find += 1
            else:
                break
            i += 1

        return find
