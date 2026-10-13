class Solution:
    def mostPoints(self, questions: list[list[int]]) -> int:
        n = len(questions)
        dp= [-1]*n

        def solve(i):
            if i >=n:
                return 0
            if dp[i]!=-1:
                return dp[i]
            
            take = questions[i][0] + solve(i+questions[i][1]+1)
            dtake = solve(i+1)

            dp[i] = max(take, dtake)
            return dp[i]
        return solve(0)