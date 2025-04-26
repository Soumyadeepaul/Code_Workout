#https://leetcode.com/contest/biweekly-contest-155/problems/find-the-most-common-response/

class Solution:
    def findCommonResponse(self, responses: List[List[str]]) -> str:
        for i in range(len(responses)):
            responses[i]=list(set(responses[i]))
        hashmap={}
        result=[]
        maxx=0
        for i in responses:
            for j in i:
                if j not in hashmap:
                    hashmap[j]=1
                else:
                    hashmap[j]+=1
        for i in hashmap.items():
            if i[1]>maxx:
                result=[]
                result.append(i[0])
                maxx=i[1]
            elif i[1]==maxx:
                result.append(i[0])
        result=sorted(result)
        #print(result,hashmap)
        return result[0]
