
def permutation(arr,ind):
    if len(arr)==ind:
        print(arr)
        return
    for i in range(ind,len(arr)):
        arr[ind],arr[i]=arr[i],arr[ind]
        permutation(arr,ind+1)
        arr[ind],arr[i]=arr[i],arr[ind]  #backtracking for outting array in original format
        
    
        
    
if __name__ == "__main__":
    arr=[1,2,3]
    permutation(arr,0)
    
