class Solution:
    def longestOnes(self, nums: list[int], k: int) -> int:
        n = len(nums)
        l,r,zeros,ans =0,0,0,0
       
        while r<n:
           
            if nums[r] ==0:
                zeros+=1
            if zeros >k:

                while zeros> k:

                    if nums[l]==0:
                        zeros-=1
                    l+=1
            r+=1
            ans = max(ans, r-l)
        return ans
        
 