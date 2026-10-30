from collections import Counter
class Solution:
    def divideArray(self, nums: list[int]) -> bool:
        lst = Counter(nums)
        vals = list(lst.values())
        for val in vals:
            if val%2!=0:
                return False
        return True
        