#https://leetcode.com/problems/search-a-2d-matrix/

class Solution:
    def searchMatrix(self, arr: List[List[int]], x: int) -> bool:
        #BINARY SEARCH
        rows=len(arr)
        while len(arr)!=1:
            rows=len(arr)
            mid=rows//2
            if arr[mid][0]>x:
                arr=arr[:mid][:]
            else:
                arr=arr[mid:][:]
        arr=arr[0]
        while len(arr)!=1:
            idx=len(arr)
            mid=idx//2
            if arr[mid]>x:
                arr=arr[:mid]
            else:
                arr=arr[mid:]
        if arr[0]==x:
            return True
        return False

            
