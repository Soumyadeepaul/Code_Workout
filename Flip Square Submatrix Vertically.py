##https://leetcode.com/problems/flip-square-submatrix-vertically/

class Solution:
    def reverseSubmatrix(self, grid: List[List[int]], x: int, y: int, k: int) -> List[List[int]]:
        end=x+k-1
        for i in range(x,x+(k//2)):
            store=grid[i][y:y+k]
            grid[i][y:y+k]=grid[end][y:y+k]
            grid[end][y:y+k]=store
            end-=1
        return grid

