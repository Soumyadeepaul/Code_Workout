#

def amazingStrings(first, second, third):
    
    # Write your code here
    # Return a string 'YES' or 'NO' denoting the answer
    hashmap={}
    for i in first:
        if i in hashmap:
            hashmap[i]+=1
        else:
            hashmap[i]=1
    
    for i in second:
        if i in hashmap:
            hashmap[i]+=1
        else:
            hashmap[i]=1

    for i in third:
        if i in hashmap:
            hashmap[i]-=1
        
        else:
            return "NO"
        
        if hashmap[i]==-1:
            return 'NO'
    if len(first)+len(second)!=len(third):
        return "NO"
    return 'YES'
