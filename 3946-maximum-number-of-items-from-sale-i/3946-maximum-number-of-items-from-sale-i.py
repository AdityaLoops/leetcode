class Solution:
    def maximumSaleItems(self, items: List[List[int]], budget: int) -> int:
        n = len(items)
        bonus = [0] * n

        for i in range(n):
            cnt = 0
            for j in range(n):
                if i != j and items[j][0] % items[i][0] == 0:
                    cnt += 1
            bonus[i] = cnt
        dp = [float("-inf")] * (budget + 1)
        dp[0] = 0

        for i in range(n):
            p = items[i][1]
            b = bonus[i]
            buy = [float("-inf")] * (budget + 1)

            for c in range(p, budget + 1):
                buy[c] = max(dp[c - p] + b + 1, buy[c - p] + 1)
            for c in range(budget + 1):
                dp[c] = max(dp[c], buy[c])

        return max(dp)
