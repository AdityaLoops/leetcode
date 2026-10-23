class Solution:
    def sortPermutation(self, nums: List[int]) -> int:
        ans =0
        flag = True
        for i, k in enumerate(nums):
            if i != k:
                if flag:
                    ans = k
                    flag = False
                ans = ans & k
        return ans