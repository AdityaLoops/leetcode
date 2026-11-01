class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        ans = 0
        for n in nums:
            ans += min(n%3, 1)
        return int(ans)