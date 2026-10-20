class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        n = len(s)
        ans =0
        l,r=0,0
        cnt =0
        while r<n:
            if s[r] in 'aeiou':
                cnt+=1
            r+=1
            while r-l>k:
                if s[l] in "aeiou":
                    cnt-=1
                l+=1
            ans = max(ans, cnt)
        return ans