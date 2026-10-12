class Solution:
    def countSubstrings(self, s: str, t: str) -> int:
        n = len(s)
        m = len(t)
        dp = [[-1]* m for _ in range(n)]
        ans =0
        
            

        def solve(i, j):
            count =0
            mismatch = 0
            length =0
            if dp[i][j]!=-1:
                return dp[i][j]

            while i + length < n and j + length < m:
                if s[i+length] != t[j+length]:
                    mismatch +=1
                if mismatch > 1:
                    break
                if mismatch ==1:
                    count+=1
                length +=1
            
            dp[i][j] = count

            
            return dp[i][j] 

        
        for x in range(n):
                for y in range(m):
                    ans += solve(x,y)
        return ans

        
