#https://leetcode.com/problems/evaluate-division/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def calcEquation(
        self, equations: List[List[str]], values: List[float], queries: List[List[str]]
    ) -> List[float]:
        hashmap = {}
        present = set()
        #CREATE a graph in form of hashmap    'a':['b',b/a] (b/a)=values[i], similarly 'b':['a',a/b]
        for i, eq in enumerate(equations):
            a, b = eq
            present.add(a)
            present.add(b)
            if a not in hashmap:
                hashmap[a] = [[b, values[i]]]
            else:
                hashmap[a].append([b, values[i]])
            if b not in hashmap:
                hashmap[b] = [[a, 1 / values[i]]]
            else:
                hashmap[b].append([a, 1 / values[i]])
        
        result = []
        for q in queries:
            a, b = q
            if a not in present or b not in present: #if not a graph node
                result.append(-1)
            else:
                #BFS
                queue=[[a,1]]  #1 because we r tracking multiplication values
                visited=set()
                found=0
                while queue:
                    node,value=queue.pop(0)
                    if node==b:
                        found=1
                        result.append(value)
                        break
                    else:
                        for neighbour, weight in hashmap[node]:
                            if neighbour not in visited:
                                queue.append([neighbour,weight*value])
                                visited.add(neighbour)
                if found==0:
                    result.append(-1)


        return result
