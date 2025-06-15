#

def towerOfHanoi(n):
    # Write your code here
    # Return a 2-D array
    
    def hanoi(n,l,r,m,stack):
        if n==0:
            return stack
        stack=hanoi(n-1,l,m,r,stack)
        stack.append([l,r])
        stack=hanoi(n-1,m,r,l,stack)
        return stack

    
    stack=hanoi(n,1,2,3,[])
    return stack
