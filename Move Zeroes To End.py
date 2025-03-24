#https://www.naukri.com/code360/problems/interview-shuriken-41-move-zeroes-to-end_240143

def pushZerosAtEnd(arr):
    # write your code here
    i=0
    j=len(arr)
    count0=0   #to maintain the last element to check else infinite loop
    #due to the continuous 0's at the end
    #[1,0,2,4,0]
    # i       j
    #[1,2,4,0,0]
    #     i ^j-count0
    while i<j-count0:
        if arr[i]==0:
            arr.pop(i)
            arr.append(0)
            count0+=1
        else:
            i+=1
    return arr
