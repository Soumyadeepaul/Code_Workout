#

from typing import List

def generateString(N: int) -> List[str]:
    # write your code here
    def subset(idx,N,stack,result):
        if idx==N:
            result.append(stack)
            return result
        result=subset(idx+1,N,stack+'0',result)

        if (not stack )or (stack and stack[-1]!='1'):
            result=subset(idx+1,N,stack+'1',result)
        return result

    return subset(0,N,'',[])
