#https://www.naukri.com/code360/problems/factorial_975273

def factorial(n):
    # Write your code here
    # Print the factorial value.
    
    def f(n,val):
        if n==1:
            return val
        return f(n-1,val*n)
    print(f(n,1))


