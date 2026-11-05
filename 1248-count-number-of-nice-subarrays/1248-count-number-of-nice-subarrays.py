class Solution:
    def numberOfSubarrays(self, nums: list[int], k: int) -> int:
        for i,n in enumerate(nums):
            if n%2==0:
                nums[i] = 0
            else:
                nums[i]= 1
        
        pref = [nums[0]]
        

        for i in range(1,len(nums)):
            pref.append(pref[i-1]+ nums[i])
        
        mp = {0:1}

        for x in pref:
            mp[x] = mp.get(x, 0) +1
        
        ans =0
        for x in pref:
            if x >= k:
                ans += mp[x-k]
        return ans
