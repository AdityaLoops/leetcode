from collections import Counter
class Solution:
    def uniqueOccurrences(self, arr: list[int]) -> bool:
        cnt = Counter(arr)
        vals = list(cnt.values())
        return len(vals) == len(set(vals))