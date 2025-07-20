#https://leetcode.com/contest/weekly-contest-459/problems/count-number-of-trapezoids-i/description/

#TLE

class Solution:
    def countTrapezoids(self, points: List[List[int]]) -> int:
        
        ys={}
        indexs=set()
        parallel=0
        for i,j in points:
            if j not in ys:
                ys[j]=1
            else:
                ys[j]+=1
                parallel+=1
                indexs.add(j)
        if parallel==1 or parallel==0:
            return 0
        indexs=list(indexs)
        result=0
        for i in range(len(indexs)-1):
            x=ys[indexs[i]]
            val=(x*(x-1))//2
            trap=0
            for j in range(i+1,len(indexs)):
                y=ys[indexs[j]]
                val1=(y*(y-1))//2
                trap+=(val*val1)

            result+=trap
        
        return result©leetcode
