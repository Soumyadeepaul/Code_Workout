#https://www.naukri.com/code360/problems/number-pattern-3_893189

def numberPattern(n):

    # Write your code here.
    # Return a 2-d list of strings.
    answer=[]
    for i in range(1,n+1):
        current=[]
        if i==1:
            current.append(1)
        elif i==2:
            current.extend([1,1])
        else:
            current=[1,1]
            for j in range(i-1,1,-1):
                current.insert(1,2)
        answer.append(current)
    return answer
