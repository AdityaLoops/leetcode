class Solution:
    def digitSum(self, s: str, k: int) -> str:
        while len(s)>k:
            curr=""
            cnt =0
            sm=0
            for x in s:
                sm += int(x)
                cnt+=1
                if cnt ==k:
                    curr+= str(sm)
                    cnt=0
                    sm =0
            if len(s)%k !=0:
                curr+= str(sm)
          
            s= curr

        return s
