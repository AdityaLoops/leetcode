class Solution:
    def minSubArrayLen(self, target: int, nums: list[int]) -> int:
        n = len(nums)
        l,r=0,0
        ans=10000000
        currsum=0
        flag = True
        while r<n:
            currsum+= nums[r]
            r+=1
            while currsum >=target:
                ans = min(ans, r-l)
                flag = False
                currsum-=nums[l]
                l+=1
        if flag:
            return 0
        return ans