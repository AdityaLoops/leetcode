class Solution:
    def minimumSumSubarray(self, nums: List[int], l: int, r: int) -> int:
        n = len(nums)
        pref=[0]*(n+1)
        
        for i in range(n):
            pref[i+1] = pref[i] + nums[i]
            
        ans=10000000
       
        for i   in range(n):
            
            for j in range(i+l, min(i+r, n)+1):
                curr = pref[j] - pref[i]
             
                if curr >0:
                    ans = min(ans,curr)
        if ans == 10000000:
            return -1
        return ans