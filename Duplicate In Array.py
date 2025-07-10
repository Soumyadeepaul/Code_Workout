#

def findDuplicate(arr):
    # Write your code here

    hashmap={}
    result=0
    for i in arr:
        if i in hashmap:
            hashmap[i]+=1
            if hashmap[i]==2:
                result=i
        else:
            hashmap[i]=1
    return result
