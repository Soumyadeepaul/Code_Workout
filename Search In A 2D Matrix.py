#https://www.naukri.com/code360/problems/search-in-a-2d-matrix_980531

def searchMatrix(mat: [[int]], target: int) -> bool:
    # Write your code here.
    #binary search rowwise
    cols=len(mat[0])
    while mat:
        rows=len(mat)
        mid=rows//2
        if mat[mid][0]<=target and mat[mid][cols-1]>=target:
            mat=mat[mid][:]
            break
        elif mat[mid][0]>target:
            mat=mat[:mid][:]
        else:
            mat=mat[mid+1:][:]
    #binary search columnwise
    while mat:
        i=len(mat)
        mid=i//2
        if mat[mid]==target:
            return True
        elif mat[mid]>target:
            mat=mat[:mid]
        else:
            mat=mat[mid+1:]
    return False
