#https://leetcode.com/problems/keys-and-rooms/description/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        num_of_rooms=len(rooms)
        keys=set([0])
        visited=set([])
        while keys:
            key=keys.pop()
            if key not in visited:
                keyFound=rooms[key]
                for i in keyFound:
                    if i not in keys:
                        keys.add(i)
                visited.add(key)
        if len(visited)==num_of_rooms:
            return True
        return False
        
