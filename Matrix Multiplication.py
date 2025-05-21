mat1=[[1,2,3],[4,5,6]]
mat2=[[1,2],[3,4],[5,6]]

for i in mat1:
    print(i)
for i in mat2:
    print(i)

mat2Transpose=[]
for i in range(len(mat2[0])):
    stack=[]
    for j in range(len(mat2)):
        stack.append(mat2[j][i])
    mat2Transpose.append(stack)

print("A Matrix:")
for i in mat1:
    print(i)
print("B Transpose Matrix:")
for i in mat2Transpose:
    print(i)

#[A]*[B](transpose)=C
newMat=[[None for _ in range(len(mat1))]for _ in range(len(mat2[0]))]
for i in range(len(mat1)):
    for j in range(len(mat2Transpose)):
        val=0
        for k in range(len(mat1[0])):
            val+=mat1[i][k]*mat2Transpose[j][k]
        newMat[i][j]=val
