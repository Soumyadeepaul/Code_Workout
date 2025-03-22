#https://www.naukri.com/code360/problems/three-sum_6922132

def triplet(n: int, arr: [int]) -> [[int]]:
    # Write your code here.
    result=[]
    triplet=[]
    for i in range(n-1):
        target=-arr[i]
        setList=set()
        for j in range(i+1,n):
            find=target-arr[j]
            #always getting checking in back side like...
            #   i.........j
            #finding z ^
            if find in setList:
                result=[arr[i],arr[j],find]
                result=sorted(result)
                if result not in triplet:
                    triplet.append(result)
            setList.add(arr[j])
    return triplet

            
