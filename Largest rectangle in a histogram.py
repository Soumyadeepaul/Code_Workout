#https://www.naukri.com/code360/problems/largest-rectangle-in-a-histogram_1058184


def largestRectangle(arr):
    # Write your code here.

    #TAKING EVERY ELEMENT AS HEIGHT, and getting width from left and right comparison O(n^2)
    #we can also use the idea of next Greater element (here next smaller element right to left traverse [and storing the index]) O(n) -> stack
    largest=0
    i=arr
    for j in range(len(i)):
        height=i[j]
        width=1
        for z in range(j+1,len(i)):
            if i[z]>=height:
                width+=1
            else:
                break
        for z in range(j-1,-1,-1):
            if i[z]>=height:
                width+=1
            else:
                break
        area=height*width
        if largest<area:
            largest=area
    return largest
