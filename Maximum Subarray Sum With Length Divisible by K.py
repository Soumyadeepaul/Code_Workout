#https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/description/?envType=daily-question&envId=2025-11-27


class Solution:
    def maxSubarraySum(self, nums, k):
        summ = 0
        l = len(nums)
        minimum = [float('inf')] * k
        minimum[0] = 0
        result = float('-inf')    # LLONG_MIN

        for i in range(l):
            summ += nums[i]
            rem = (i + 1) % k
            result = max(result, summ - minimum[rem])
            minimum[rem] = min(minimum[rem], summ)

        return result
