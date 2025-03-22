#https://www.naukri.com/code360/problems/fourth-largest-element-in-the-array_630422

def getFourthLargest(arr, n):
    # Write your code here
    largest=[-2147483648,-2147483648,-2147483648,-2147483648]
    for i in arr:
        if i>=largest[-1]: #greater then 4th possible yet
            for j in range(4):
                if i>largest[j]:
                    largest.insert(j,i)
                    largest.pop()
                    break
    return largest[-1]
