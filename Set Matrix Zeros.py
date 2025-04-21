#https://www.naukri.com/code360/problems/set-matrix-zeros_3846774

# from math import *
# from collections import *
# from sys import *

# from typing import List

# def setZeros(matrix: List[List[int]]) -> None:
# 	# Write your code here.
#     row=len(matrix)
#     column=len(matrix[0])
#     position=[]
#     for i in range(row):
#         for j in range(column):
#             if [i,j] in position:
#                 pass
#             elif matrix[i][j]==0:
#                 for z in range(column):
#                     if matrix[i][z]!=0 and [i,z] not in position:
#                         position.append([i,z])
#                     matrix[i][z]=0
#                 for z in range(row):
#                     if matrix[z][j]!=0 and [z,j] not in position:
#                         position.append([z,j])
#                     matrix[z][j]=0


from math import *
from collections import *
from sys import *

from typing import List

def setZeros(matrix: List[List[int]]) -> None:
	# Write your code here.
    row=len(matrix)
    column=len(matrix[0])
    rows=[]
    columns=[]
    for i in range(row):
        for j in range(column):
            if matrix[i][j]==0:
                if i not in rows:
                    rows.append(i) #store it for changing it later
                if j not in columns:
                    columns.append(j)

    for i in rows:
        matrix[i]=[0 for _ in range(column)]
    for j in columns:
        for i in range(row):
            matrix[i][j]=0
    return matrix
