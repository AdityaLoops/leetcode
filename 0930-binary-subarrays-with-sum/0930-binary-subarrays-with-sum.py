class Solution:
    def numSubarraysWithSum(self, nums: list[int], goal: int) -> int:
        pref=[nums[0]]
        for i in range(1, len(nums)):
            pref.append(pref[i-1] + nums[i])
        
        mp = {0:1}
        ans=0
        for x in pref:
            ans += mp.get(x-goal, 0)
            mp[x] = mp.get(x,0) +1
        return ans 
        

            