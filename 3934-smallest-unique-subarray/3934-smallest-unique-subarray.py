class Solution:
    def smallestUniqueSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        low = 0 
        high = n
        ans =0
        while low<=high:
            length = low + (high-low)//2
            base=10
            mod = 10**9 + 7

            freq = {}
            
            hash_val = 0
            for i in range(length):
                hash_val = (hash_val*base+ nums[i])%mod
            freq[hash_val] = freq.get(hash_val, 0) +1
            
            power = pow(base, length -1, mod)

            for i in range( length, n):
                hash_val = (hash_val - nums[i-length]*power)%mod
                hash_val = (hash_val * base + nums[i])%mod
                freq[hash_val] = freq.get(hash_val, 0)+1
            unique = 1 in freq.values()

            if unique:
                ans = length
                high = length-1
            else:
                low = length + 1
        return ans

                
