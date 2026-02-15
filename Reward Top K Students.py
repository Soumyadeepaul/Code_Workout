##https://leetcode.com/problems/reward-top-k-students/description/

class Solution:
    def topStudents(self, positive_feedback: List[str], negative_feedback: List[str], report: List[str], student_id: List[int], k: int) -> List[int]:
        dic={}
        positive_feedback=set(positive_feedback)
        negative_feedback=set(negative_feedback)
        for i in student_id:
            dic[i]=0
        for i in range(len(report)):
            store=list(report[i].split(' '))
            for j in store:
                if j in positive_feedback:
                    dic[student_id[i]]+=3
            for j in store:
                if j in negative_feedback:
                    dic[student_id[i]]-=1
            
        pq=[]

        for i,j in dic.items():
            heapq.heappush(pq,(-j,i))
        
        result=[]
        while(k!=0):
            v,s=heapq.heappop(pq)
            result.append(s)
            k-=1
        return result
