#https://www.naukri.com/code360/problems/bfs-in-graph_973002

from typing import List


def bfsTraversal(n: int, adj: List[List[int]]) -> List[int]:
    # write your code here
    queue=[0]
    queue.extend(adj[0])
    result=[]
    while queue:
        key=queue[0]
        queue=queue[1:]
        if key not in result:
            value_according=adj[key]
            for i in value_according:
                if i not in queue and i not in result:
                    queue.append(i)
            result.append(key)
    return result
