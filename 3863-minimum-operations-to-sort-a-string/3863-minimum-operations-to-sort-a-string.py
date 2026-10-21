class Solution:
    def minOperations(self, s: str) -> int:
        n = len(s)
        cnt =0
        x = ''.join(sorted(s))
        if s == x:
            return 0
        if n ==2 and s[0]>s[1]:
            return -1
        mn,mx = 'z', 'a'
        for stg in s:
            if stg > mx:
                
                mx = stg
            if stg < mn:
               
                mn = stg
        for stg in s:
            if stg == mx or stg == mn:
                cnt+=1
        if s[0] == mn or s[-1] == mx:
            return 1
        elif s[0] == mx and s[-1]== mn and cnt <=2:
            return 3
        else:
            return 2