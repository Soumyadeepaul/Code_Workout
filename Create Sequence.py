#

def createSequence(n):
    # Write your code here.
    # result=[]
    # for i in range(2,n+1):
    #     store=i
    #     while store:
    #         if store%10==2 or store%10==5:
    #             store=store//10
    #         else:
    #             break
    #     if store==0:
    #         result.append(i)
    # return result



    #select 2 or 5
    def subset(n,stack,result):
        if stack and int(stack)>n:
            return result
        if stack:
            result.append(int(stack))
        result=subset(n,stack+'2',result)
        result=subset(n,stack+'5',result)
        return result
        
        
    
    result=subset(n,'',[])
    return sorted(result)
