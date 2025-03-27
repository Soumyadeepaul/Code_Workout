#https://www.naukri.com/code360/problems/binomial-coefficient-problem_1229410?interviewProblemRedirection=true&practice_topic%5B%5D=Divide%20and%20Conquer&difficulty%5B%5D=Easy&leftPanelTabValue=PROBLEM

def calculateBinomialCoefficient(n, r): 
    # Write your code here.
    nemorator=n
    times=r
    denomerator=r
    while times>1:
        times-=1
        n=n-1
        nemorator=nemorator*(n)
        denomerator=denomerator*(times)
    return (nemorator//denomerator)%(10**9+7)
