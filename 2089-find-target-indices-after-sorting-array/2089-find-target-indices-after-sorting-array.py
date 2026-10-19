class Solution:
    def targetIndices(self, nums: list[int], target: int) -> list[int]:
        nums.sort()
        ans=[]
        for i, n in enumerate(nums):
            if n == target:
                ans.append(i)
        return ans