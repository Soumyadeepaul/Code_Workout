#https://www.naukri.com/code360/problems/divide-two-integers_1112617

from typing import List

def divideTwoInteger(dividend: int, divisor: int) -> int:
    # write your code here
    manipulate=0
    if dividend<0 and divisor>0:
        manipulate=1
        dividend=abs(dividend)
    elif dividend>0 and divisor<0:
        manipulate=1
        divisor=abs(divisor)
    elif divisor<0 and dividend<0:
        divisor=abs(divisor)
        dividend=abs(dividend)
    result=0
    value=0
    while value<dividend:
        if dividend-value<divisor:
            break
        result+=1
        value+=divisor
    if manipulate==1:
        return 0-result
    return result
