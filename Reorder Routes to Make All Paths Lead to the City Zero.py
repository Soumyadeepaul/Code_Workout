#https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        ########################
        #TLE
        # count=0
        # hashmap={}
        # #connections=sorted(connections,key=lambda x:x[1])
        # while connections:
        #     start,end=connections.pop(0)
        #     if start==0:
        #         count+=1
        #         if end not in hashmap:
        #             hashmap[end]=set([0])
        #     elif end==0:
        #         if start not in hashmap:
        #             hashmap[start]=set([0])
        #     else:
        #         if start in hashmap:
        #             if 0 in hashmap[start]:
        #                 count+=1
        #                 if end not in hashmap:
        #                     hashmap[end]=set([0])
        #         elif end in hashmap:
        #             if 0 in hashmap[end]:
        #                 if start not in hashmap:
        #                     hashmap[start]=set([0])
        #         else:
        #             connections.append([start,end])
        # #print(hashmap)
        # return count
        ###################################
        def dfs(connection,visited,node):
            change=0
            visited[node]=True
            for i in connection[node]:
                if not visited[abs(i)]:
                    change+=dfs(connection,visited,abs(i)) + (i>0)
            return change
        newConnection={i:[] for i in range(n)}
        for start,end in connections: #TO MAKE Bi DIRECTIONAL
            newConnection[start].append(end)
            newConnection[end].append(-start)#NEW CONNECTION
        visited={i:False for i in range(n)}
        return dfs(newConnection,visited,0)

