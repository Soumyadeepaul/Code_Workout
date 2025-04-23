#https://www.naukri.com/code360/problems/allocate-books_1090540

#SAME LIKE PAINTER'S PARTITION ALGO

def possible(arr,mid,m):
    pageSum=0
    studentAllocated=1
    for i in arr:
        if pageSum+i<=mid: #if sum<=mid, then allocate to same person
            pageSum+=i
        else:
            studentAllocated+=1
            #1st condition means, more student gets allocated, 2nd condition means arr[i] is more than mid 
            if studentAllocated>m or i>mid:
                return False
            pageSum=i #start with new person
    return True


def findPages(arr: [int], n: int, m: int) -> int:

    # Write your code here
    # Return the minimum number of pages
    if m>n:
        return -1
    start=0
    end=sum(arr)
    result=-1
    while start<=end:
        mid=start+ (end-start)//2  #mid is used for checking optimality
        if possible(arr,mid,m):
            result=mid  #why no checking of min... always mid gets lesser (optimized)
            end=mid-1 #if already possible search lower value
        else:
            start=mid+1
    return result


#[10,20,30,40]
#start=0
#end=100
#mid1=50
#[10,20],[30],[40] not possible with 50
#mid2=75
#[10,20,30],[40] may be the ans 75
#mid3=62
#[10,20,30],[40] may be the ans 62
#mid4=55
#[10,20],[30],[40] not possible with 55
#mid5=60
#[10,20,30],[40] possible with 60..... and so on till start<=end

#we observe ans gets optimized from 75 -> 62 ->60




    
