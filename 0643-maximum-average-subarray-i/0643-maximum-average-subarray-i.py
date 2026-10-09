class Solution:
    def findMaxAverage(self, nums: list[int], k: int) -> float:
        summ=0.0
        ans = 0.0
        l = 0
        r = 0
        while r < k:
            summ += nums[r]
            r+=1
        ans = summ/k
        while(r < len(nums)):
            summ += nums[r]
            summ -= nums[l]
            ans = max(ans, (summ/k))
            r+=1
            l+=1
        return ans