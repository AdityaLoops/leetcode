class Solution:
    def maxProduct(self, nums: list[int]) -> int:
        n = len (nums)
       

        mini=nums[0]
        maxi=nums[0]
        ans = nums[0]
        for i in range(1,n):
            num=nums[i]
            prev_max = maxi
            prev_min = mini
            maxi = max ( prev_max*num, num, prev_min*num)
            mini = min(prev_min*num, num, prev_max*num)
            ans = max(ans, maxi)
        return ans
        
