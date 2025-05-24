#https://leetcode.com/problems/gas-station/description/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        if sum(gas)<sum(cost):
            return -1
        i=0
        #FIND THE STARTING POSITION
        while i<len(gas):  
            if gas[i]<cost[i]: #CANT BE A STARTING POS
                pass
            else:
                g=0
                cannt=0
                failed=0
                #CHECK till gas exhaust
                #if gas doesnt exhaust before reaching the end of the list.... its the answer
                #if exhausted... the again start to search from where it got exhasuted
                for j in range(i,len(gas)):
                    g+=gas[j]
                    g-=cost[j]
                    if g<0:
                        cannt=1
                        failed=j
                        break
                if cannt==0:
                    return i
                i=failed
            i+=1
        return -1
