class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        maxi, maxd=1,1
        l, r  =0,1
        n = len(nums)
        cnt = 1
        while r<n:
            if nums[r]>nums[r-1]:
                cnt+=1
            else:
                cnt = 1
                l = r
            r+=1
            maxi = max(maxi, cnt)
        l,r = 0,1
        cnt = 1
        while r<n:
            if nums[r]<nums[r-1]:
                cnt+=1
            else:
                cnt = 1
                l=r
            r+=1
            maxd= max(maxd, cnt)
        return max(maxd, maxi)

