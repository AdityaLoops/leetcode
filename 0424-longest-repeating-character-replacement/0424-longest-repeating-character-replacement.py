class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        n=len(s)
        l,r,ans,maxf =0,0,0,0
        freq ={}
        while r<n:
            c = s[r]
            freq[s[r]]= freq.get(s[r],0) +1
            maxf = max(maxf, freq[s[r]])
            r+=1

            while (r-l) -  maxf > k:
                freq[s[l]]-=1
                if freq[s[l]]==0:
                    del freq[s[l]]
                l+=1
            ans = max(ans, r-l)
        return ans