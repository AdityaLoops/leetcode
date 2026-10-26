from collections import deque


class Solution:
    def countIslands(self, grid: List[List[int]], k: int) -> int:
        n = len(grid)
        m = len(grid[0])
        viz = [[0] * m for _ in range(n)]
        ans = 0

        for i in range(n):
            for j in range(m):
                total = 0
                if grid[i][j] > 0 and viz[i][j] == 0:
                    q = deque()
                    drow = [1, 0, -1, 0]
                    dcol = [0, 1, 0, -1]

                    q.append((i, j))
                    viz[i][j] = 1
                    total += grid[i][j]

                    while q:

                        r, c = q.popleft()


                        for d in range(4):
                            col = dcol[d] + c
                            row = drow[d] + r

                            if (
                                col >= 0
                                and row >= 0
                                and col < m
                                and row < n
                                and grid[row][col] > 0
                                and viz[row][col] == 0
                            ):
                                total += grid[row][col]
                                viz[row][col] = 1
                                q.append((row, col))
                    if total and total % k == 0:
                        print(total)
                        ans += 1
        return ans
