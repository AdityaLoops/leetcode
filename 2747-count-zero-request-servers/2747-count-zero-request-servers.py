class Solution:
    def countServers(self, n: int, logs: List[List[int]], x: int, queries: List[int]) -> List[int]:
        s = len(queries)
        l,r =0,0
        lst = [0]*len(queries)
        
        i=0

        queries = sorted((q, idx) for idx, q in enumerate(queries))
        logs.sort(key=lambda x: x[1])

        freq={}
        for q, idx in queries:

            while r<len(logs) and logs[r][1] <=q:
                freq[logs[r][0]] = freq.get(logs[r][0],0) +1
                r+=1
            while l<r and logs[l][1] < q - x:
                freq[logs[l][0]] -= 1
                if freq[logs[l][0]] ==0:
                    del freq[logs[l][0]]
                l+=1
            i+=1
            cnt = n- len(freq)
            lst[idx] = cnt
        return lst

            