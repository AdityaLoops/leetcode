class Solution:
    def numOfSubarrays(self, arr: list[int]) -> int:
        even =1
        odd = 0
        sm =0
        ans =0
        for x in arr:
            sm += x
            if sm%2==0:
                even+=1
                ans+=odd
            else:
                odd+=1
                ans+=even
        return int(ans%(1e9 +7))