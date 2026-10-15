class Solution:
    def totalFruit(self, fruits: list[int]) -> int:
        n = len(fruits)
        l =0
        r=0
        freq = {}
        ans =0
        
        while ( r< n):
            freq[fruits[r]] = freq.get(fruits[r], 0) +1
            r+=1
            while len(freq)>2:
                freq[fruits[l]]-=1
                if freq[fruits[l]]==0:
                    del freq[fruits[l]]
                l+=1
            
            ans =max(ans, r-l)
        return ans


  
