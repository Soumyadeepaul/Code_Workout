#https://leetcode.com/problems/find-the-safest-path-in-a-grid/?envType=daily-question&envId=2026-07-01


from collections import deque
import heapq

class Solution:
    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:

        mod = 10**9 + 7
        r = len(grid)
        c = len(grid[0])

        newGrid = [[mod for _ in range(c)] for _ in range(r)]
        q = deque()

        for i in range(r):
            for j in range(c):
                if grid[i][j]:
                    newGrid[i][j] = 0
                    q.append([i, j, 0])

        def bfs():
            dirs = [[0,1],[1,0],[-1,0],[0,-1]]

            while q:
                x1, y1, cost = q.popleft()

                for x, y in dirs:
                    nx = x1 + x
                    ny = y1 + y

                    if nx < 0 or ny < 0 or nx >= r or ny >= c:
                        continue

                    if newGrid[nx][ny] != mod:
                        continue

                    newGrid[nx][ny] = cost + 1
                    q.append([nx, ny, cost + 1])

        bfs()

        def dij():
            visited = [[0 for _ in range(c)] for _ in range(r)]
            dirs = [[0,1],[1,0],[-1,0],[0,-1]]
            maxHeap = []

            heapq.heappush(maxHeap, (-newGrid[0][0], [0,0]))

            while maxHeap:
                ans, idx = heapq.heappop(maxHeap)

                if visited[idx[0]][idx[1]]:
                    continue

                visited[idx[0]][idx[1]] = 1

                if idx[0] == r-1 and idx[1] == c-1:
                    return -ans

                for x, y in dirs:
                    nx = idx[0] + x
                    ny = idx[1] + y

                    if nx < 0 or ny < 0 or nx >= r or ny >= c or visited[nx][ny]:
                        continue

                    heapq.heappush(maxHeap, (max(ans, -newGrid[nx][ny]), [nx, ny]))

            return 0

        return dij()
