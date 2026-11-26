class Solution:
    def canAliceWin(self, n: int) -> bool:
        cnt  =0
        for i in range(10,0,-1):
            n = n-i
            cnt+=1
            if n<0:
                if cnt%2 == 0:
                    return True
                else:
                    return False
        return True
                