#https://www.naukri.com/code360/problems/square-root-integral_893351
#BINARY SEARCH
def floorSqrt(n):
   # write your code logic here .
   start=0
   end=n
   ans=-1
   while start<=end:
      mid=start+(end-start)//2
      val=mid*mid
      if val==n: #perfect Square
         return mid
      elif val<n: #if multiplication < needed, we can say it could be possible floor value : 2*2=4<6... may be 2 is the answer.. becoz ans likes between [2,3]
         ans=mid
         start=mid+1 #search from bigger number
         
      else:
         end=mid-1 #if greater than needed, move towards smaller
   return ans

n= int(input())
print(floorSqrt(n))
