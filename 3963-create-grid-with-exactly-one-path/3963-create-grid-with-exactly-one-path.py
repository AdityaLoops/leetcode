class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
        lst = []

        for i in range(m):
            strn=""
            for j in range(n):
                if i == 0 or j == n-1:
                    strn += '.'
                else:
                    strn += '#'
            lst.append(strn)
        return lst
