#https://leetcode.com/problems/equal-row-and-column-pairs/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        hashmap={}
        j=0
        count=0
        while j<len(grid[0]):
            i=0
            row=[]
            while i<len(grid):
                row.append(grid[i][j])
                i+=1
            j+=1
            for k in grid:
                if k==row:
                    count+=1
        return count
