class Solution:
    def maxSumOfSquares(self, num: int, sum: int) -> str:
        
        remaining_sum=sum
        if sum > 9 * num:
            return ""

        ans=""

        for _ in range(1,num+1):
            # if remaining_sum >=n:
            for i in range(9,-1,-1):
                if i<= remaining_sum:
                    ans+= str(i)
                    remaining_sum -=i
                    break

        
        return ans
