class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        n= len(prices)
        dp= [[[-1]*3 for _ in range(2)]for _ in range(n+1)]

        def solve(i, state, rem):
            if i>= n or rem ==0:
                return 0
            if dp[i][state][rem]!=-1:
                return dp[i][state][rem]
            ans =0
            buysell =0
            skip=0
            if state:
                buysell += prices[i] + solve(i+1,0,rem-1)
                skip = solve(i+1,1,rem)
            else:
                buysell = solve(i+1, 1, rem ) - prices[i]
                skip = solve(i+1, 0, rem)
            dp[i][state][rem] = max(buysell, skip)

            return dp[i][state][rem]
        
        return solve(0,0,2)