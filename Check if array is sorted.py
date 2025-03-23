#https://www.naukri.com/code360/problems/check-if-array-is-sorted_7444305

def arraySortedOrNot(a: [int], n: int) -> bool:
    # Write your code here.
    #merge Sort

    def mergeSort(arr,swap):
        if len(arr)>1:
            mid=len(arr)//2
            left=arr[:mid]
            right=arr[mid:]
            swap=mergeSort(left,swap)
            if swap==1:
                return swap
            swap=mergeSort(right,swap)
            if swap==1:
                return swap
            i=j=k=0
            while i<len(left) and j<len(right):
                if left[i]<=right[j]:
                    arr[k]=left[i]
                    i+=1
                else:
                    swap=1
                    return swap
                    arr[k]=right[j]
                    j+=1
                k+=1
            while i<len(left):
                arr[k]=left[i]
                i+=1
                k+=1
            while j<len(right):
                arr[k]=right[j]
                j+=1
                k+=1
        return swap
    swap=0
    swap=mergeSort(a,swap)
    if swap==1:
        return False
    return True
