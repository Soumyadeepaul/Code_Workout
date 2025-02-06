#https://www.naukri.com/code360/problems/sum-of-infinite-array_873335



def sumInRanges(arr, n, queries, q):

    # Write your function Here.
    result=[]
    summ=sum(arr)
    for i in queries:
        i[1]-=1
        i[0]-=1
        num_of_terms=i[1]-i[0]+1
        starting=i[0]%n
        ending=i[1]%n
        arr1=arr[starting:]+arr[:starting]
        looped=num_of_terms//n
        left_out=num_of_terms-(looped*n)
        value=((looped*summ)+sum(arr1[:left_out]))%(1000000007)
        result.append(value)
        

    return result

    
#[1 2 3 4 5]
#from position 2 to 8
#rearrange as [2 3 4 5 1]
#left_out terms are added later

#ERROR - TLE 
