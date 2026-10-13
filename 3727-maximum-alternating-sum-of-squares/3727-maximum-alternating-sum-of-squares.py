class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        n = len(nums)
        nums.sort(key = abs, reverse = True)
        ans =0
        for i, num in enumerate(nums):
            if i<n/2:
                ans += num*num
            else:
                ans -= num*num
        return ans